//
//  AndroidGLESWindow.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef WINDOW_H
#define WINDOW_H

#include "engine/platform/glesrenderer.h"
#include "engine/graphics/iwindow.h"

namespace engine
{
    namespace platform
    {
        class AndroidGLESWindow : public graphics::IWindow
        {

        public:
            AndroidGLESWindow();
            virtual ~AndroidGLESWindow() {}
            virtual bool Init() override;
            virtual void Dispose() override;

            virtual float GetWidth() const override;
            virtual float GetHeight() const override;
            virtual void RenderScene(graphics::Scene* scene) override;

            graphics::Texture* LoadTexture(const std::string& name);

            void SetWindow(ANativeWindow* window);
            void SetAssets(AAssetManager* assets);

        protected:
            void DrawNode(graphics::SpriteNode* node);

            bool _initialized;
            utils::Vec2 _size;
            ANativeWindow* _window;
            GLESRenderer _renderer;
        };
        typedef utils::ref_ptr<AndroidGLESWindow> WindowPtr;
    }
}
#endif // WINDOW_H