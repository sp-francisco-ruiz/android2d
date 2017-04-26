//
// Created by fjruiz.
//
#include <android/native_window.h>

#include <EGL/egl.h>
#include <GLES/gl.h>
#include <GLES2/gl2.h>

#include <string>
#include <vector>

#include "utils/logger.h"
#include "utils/lodepng.h"
#include "engine/sprite.h"
#include "engine/application.h"
#include "platform/oglesrenderer.h"
#include "platform/androidwindow.h"
#include "engine/ifilesmanager.h"

const std::string LOG_TAG("Renderer");

namespace renderutils
{
    static GLfloat positions[] =
    {
        // X      Y     Z
        -0.5f,  0.5f, 0.0f ,
        -0.5f, -0.5f, 0.0f ,
        0.5f, -0.5f, 0.0f ,
        0.5f, -0.5f, 0.0f ,
        0.5f,  0.5f, 0.0f ,
        -0.5f,  0.5f, 0.0f
    };
    static GLfloat uvs[] =
    {
        //U     V
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f
    };

    const char vertexShader[] =
            "attribute vec3 position;\n"
            "attribute vec2 uv;\n"
            "uniform mat4 proj_matrix;\n"
            "uniform mat4 model_matrix;\n"
            "varying vec2 v_uv;\n"
            "void main() {\n"
            "   v_uv = uv;\n"
            "	gl_Position = proj_matrix * model_matrix * vec4(position, 1.0);\n"
            "}";

    const char fragmentShader[] =
            "precision mediump float;\n"
            "uniform sampler2D tex;\n"
            "varying vec2 v_uv;\n"
            "void main() {\n"
            "	gl_FragColor = texture2D(tex, v_uv);\n"
            "}\n";

    GLuint compileShader(GLenum type, const char* source)
    {
        GLuint shader = glCreateShader(type);
        if (!shader)
        {
            return 0;
        }

        glShaderSource(shader, 1, &source, NULL);
        glCompileShader(shader);
        GLint compileStatus;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);

        if (compileStatus == GL_TRUE)
        {
            return shader;
        }

        GLint infoLogLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        if (infoLogLength)
        {
            char* infoLog = (char*)malloc(static_cast<size_t>(infoLogLength));
            if (infoLog)
            {
                glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);
                LOG_ERROR("Could not compile shader %d:\n%s", type, infoLog);
                free(infoLog);
            }
            glDeleteShader(shader);
        }
        return 0;
    }

    GLuint createProgram(const char* vertexSource, const char* fragmentSource)
    {
        GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
        if (!vertexShader)
        {
            return 0;
        }

        GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);
        if (!fragmentShader)
        {
            return 0;
        }

        GLuint program = glCreateProgram();
        if (!program)
        {
            return 0;
        }

        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        glDetachShader(program, vertexShader);
        glDetachShader(program, fragmentShader);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        GLint linkStatus;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
        if (linkStatus == GL_TRUE)
        {
            return program;
        }

        GLint infoLogLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
        if (infoLogLength)
        {
            char* infoLog = (char*)malloc(static_cast<size_t>(infoLogLength));
            if (infoLog)
            {
                glGetProgramInfoLog(program, infoLogLength, NULL, infoLog);
                LOG_ERROR("Could not link program:\n%s", infoLog);
                free(infoLog);
            }
        }
        glDeleteProgram(program);
        return 0;
    }

    GLuint CreateTexture(const char* filename)
    {
        GLuint texid = 0xdead;

        unsigned int size = 0;
        unsigned char* encoded = engine::Application::GetInstance().GetFilesManager().GetFileContents(filename, size);

        if(size == 0)
        {
            LOG_ERROR("file not found: %s", filename);
            return texid;
        }

        std::vector<unsigned char> decoded;
        unsigned int width, height;
        auto error = lodepng::decode(decoded, width, height, encoded, size);
        if(error)
        {
            LOG_ERROR("Fail decoding img: %s", filename);
            return texid;
        }
        free(encoded);

        glGenTextures(1, &texid);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texid);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &decoded[0]);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        return texid;
    }
}

namespace platform
{
    OGLESRenderer::OGLESRenderer()
    : _display(nullptr)
    , _surface(nullptr)
    , _context(nullptr)
    {
    }

    OGLESRenderer::~OGLESRenderer()
    {
    }

    unsigned int OGLESRenderer::GetTextureId(const std::string& fileName)
    {
        if(_textures.find(fileName) == _textures.end())
        {
            _textures[fileName] = renderutils::CreateTexture(fileName.c_str());
        }
        return static_cast<unsigned int>(_textures[fileName]);
    }

    void OGLESRenderer::Initialize(engine::IWindow* window)
    {
        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (display == EGL_NO_DISPLAY)
        {
            LOG_ERROR("eglGetDisplay() returned error %d", eglGetError());
            return;
        }
        if (!eglInitialize(display, 0, 0))
        {
            LOG_ERROR("eglInitialize() returned error %d", eglGetError());
            return;
        }

        const EGLint attribs[] =
        {
                EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
                EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
                EGL_RED_SIZE, 8,
                EGL_GREEN_SIZE, 8,
                EGL_BLUE_SIZE, 8,
                EGL_NONE
        };
        EGLConfig config;
        EGLint numConfigs;

        if (!eglChooseConfig(display, attribs, &config, 1, &numConfigs))
        {
            LOG_ERROR("eglChooseConfig() returned error %d", eglGetError());
            Dispose();
            return;
        }

        EGLint format;
        if (!eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format))
        {
            LOG_ERROR("eglGetConfigAttrib() returned error %d", eglGetError());
            Dispose();
            return;
        }

#ifdef ANDROID_NATIVE_WINDOW_H
        AndroidWindow* androidWindow = static_cast<AndroidWindow*>(window);
        ANativeWindow_setBuffersGeometry(androidWindow->GetNativeWindow(), 0, 0, format);

        EGLSurface surface = eglCreateWindowSurface(display, config, androidWindow->GetNativeWindow(), NULL);
        if (!surface)
        {
            LOG_ERROR("eglCreateWindowSurface() returned error %d", eglGetError());
            Dispose();
            return;
        }
#else
#error Platform not implemented
#endif

        EGLint contextAttribs[] =
        {
            EGL_CONTEXT_CLIENT_VERSION, 2,
            EGL_NONE
        };
        EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);
        if (context == EGL_NO_CONTEXT)
        {
            LOG_ERROR("eglCreateContext() returned error %d", eglGetError());
            Dispose();
            return;
        }

        if (eglMakeCurrent(display, surface, surface, context) == EGL_FALSE)
        {
            LOG_ERROR("eglMakeCurrent() returned error %d", eglGetError());
            Dispose();
            return;
        }

        if (!eglQuerySurface(display, surface, EGL_WIDTH, &_width) ||
            !eglQuerySurface(display, surface, EGL_HEIGHT, &_height))
        {
            LOG_ERROR("eglQuerySurface() returned error %d", eglGetError());
            Dispose();
            return;
        }

        _display = display;
        _surface = surface;
        _context = context;

        glClearColor(0, 0, 0, 0);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        program = renderutils::createProgram(renderutils::vertexShader, renderutils::fragmentShader);
        if (!program)
        {
            LOG_ERROR("Could not create program");
            return;
        }
        positionLocation = static_cast<GLuint>(glGetAttribLocation(program, "position"));
        uvLocation = static_cast<GLuint>(glGetAttribLocation(program, "uv"));
        projectionUniform = glGetUniformLocation(program, "proj_matrix");
        modelUniform = glGetUniformLocation(program, "model_matrix");
        textureUniform = glGetUniformLocation(program, "tex");

        _projMatrix.CalculateOrtho(0.0f, static_cast<float>(_width), 0.0f, static_cast<float>(_height), 0.0f, 100.0f);
    }

    void OGLESRenderer::Dispose()
    {
        eglMakeCurrent(_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        eglDestroyContext(_display, _context);
        eglDestroySurface(_display, _surface);
        eglTerminate(_display);

        _display = EGL_NO_DISPLAY;
        _surface = EGL_NO_SURFACE;
        _context = EGL_NO_CONTEXT;
    }

    void OGLESRenderer::StartFrame()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(program);
        glEnableVertexAttribArray(positionLocation);
        glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 0, renderutils::positions);
        glEnableVertexAttribArray(uvLocation);
        glVertexAttribPointer(uvLocation, 2, GL_FLOAT, GL_TRUE, 0, renderutils::uvs);
        glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, (GLfloat*)&_projMatrix);

        glActiveTexture(GL_TEXTURE0);
        glUniform1i(textureUniform, 0);
    }

    void OGLESRenderer::DrawSprite(engine::Sprite& sprite)
    {
        auto& texture = sprite.GetTexture();
        if(!texture.Valid())
        {
            return;
        }
        glBindTexture(GL_TEXTURE_2D, static_cast<GLuint>(texture.GetId()));
        glUniformMatrix4fv(modelUniform, 1, GL_FALSE, (GLfloat*)&sprite.GetTransform());

        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    void OGLESRenderer::EndFrame()
    {
        if (!eglSwapBuffers(_display, _surface))
        {
            LOG_ERROR("eglSwapBuffers() returned error %d", eglGetError());
        }
    }
}