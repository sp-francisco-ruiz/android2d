//
// Created by fjruiz.
//
#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <android/asset_manager.h>
#include <utils/mat4.h>

namespace engine
{
    class Sprite;
}

namespace platform
{
    class Renderer {

    public:
        Renderer();
        virtual ~Renderer();

        void SetAssetManager(AAssetManager *assetManager);
        void SetWindow(ANativeWindow *window);

        bool Initialize();
        void Destroy();
        void StartFrame();
        void DrawSprite(engine::Sprite &sprite);
        void EndFrame();

        int GetWidth() const;
        int GetHeight() const;

        GLuint GetTextureId(const std::string& fileName);

    private:
        int _width;
        int _height;
        ANativeWindow *_window;
        AAssetManager *_assetManager;
        EGLDisplay _display;
        EGLSurface _surface;
        EGLContext _context;
        utils::Mat4 _projMatrix;

        std::map<std::string, GLuint> _textures;
        GLuint program;
        GLuint positionLocation;
        GLuint uvLocation;
        GLint projectionUniform;
        GLint modelUniform;
        GLint textureUniform;
    };
}
#endif // RENDERER_H