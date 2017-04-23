//
// Created by fjruiz on 15/04/2017.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include <mutex>
#include <list>

#include "engine/graphics/texturecache.h"
#include "engine/platform/androidgleswindow.h"

namespace engine
{
    namespace platform
    {
        class Application
        {
        public:
            enum class InputType
            {
                BEGIN = 0,
                END
            };

            static Application& GetSharedApp();

            Application();
            ~Application();

            void Start();
            void Stop();
            void Resume();
            void Pause();
            void OnPressed();

            graphics::IWindow& GetWindow();

            void SetWindow(ANativeWindow* window);
            void SetAssets(AAssetManager* assets);

            graphics::TextureCache& GetTextureCache();

        private:
            enum class ThreadMessage
            {
                NONE = 0,
                INITIALIZE,
                EXIT
            };

            void MainLoop();
            graphics::Texture* LoadTexture(const std::string& name);

            std::list<InputType> _input;

            bool _running;

            std::mutex _mutex;
            ThreadMessage _msg;
            AndroidGLESWindow _window;
            graphics::TextureCache _texturesCache;
        };
    }
}
#endif // APPLICATION_H
