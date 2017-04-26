//
// Created by fjruiz.
//
#ifndef OGLESRENDERER_H
#define OGLESRENDERER_H

#include <map>
#include <EGL/egl.h>
#include <GLES/gl.h>

#include "engine/irenderer.h"
#include "utils/mat4.h"

namespace platform
{
    class OGLESRenderer : public engine::IRenderer
    {

    public:
        OGLESRenderer();
        virtual ~OGLESRenderer();

        void Initialize(engine::IWindow* window) override;
        void Dispose() override;
        void StartFrame() override;
        void DrawSprite(engine::Sprite& sprite) override;
        void EndFrame() override;
        unsigned int GetTextureId(const std::string& fileName) override;

    private:
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
#endif // OGLESRENDERER_H