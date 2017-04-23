//
// Created by fjruiz on 14/04/2017.
//
#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <android/asset_manager.h>
#include <engine/utils/mat4.h>

#include "engine/graphics/spritenode.h"

namespace engine
{
    class Sprite;

    namespace platform
    {
        class GLESRenderer
        {

        public:
            GLESRenderer();
            virtual ~GLESRenderer();

            void SetAssetManager(AAssetManager *assetManager);
            void SetWindow(ANativeWindow *window);

            bool Initialize();
            void Destroy();
            void StartFrame();
            void DrawSprite(engine::graphics::SpriteNode &sprite);
            void EndFrame();

            int GetWidth() const;
            int GetHeight() const;

            graphics::Texture* LoadTexture(const std::string& name);

        private:
            int _width;
            int _height;
            ANativeWindow *_window;
            AAssetManager *_assetManager;
            EGLDisplay _display;
            EGLSurface _surface;
            EGLContext _context;
            utils::Mat4 _projMatrix;

            GLuint program;
            GLuint positionLocation;
            GLuint uvLocation;
            GLint projectionUniform;
            GLint modelUniform;
            GLint textureUniform;
        };
    }
}
#endif // RENDERER_H