//
// Created by fjruiz.
//
#ifndef APPLICATION_H
#define APPLICATION_H

#include <mutex>
#include <list>
#include "renderer.h"

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
        enum class ThreadMessage
        {
            NONE = 0,
            INITIALIZE,
            EXIT
        };

        Application();

        ~Application();

        void Start();

        void Stop();

        void OnPressed();

        void SetWindow(ANativeWindow* window);
        void SetAssets(AAssetManager* assets);

    private:

        void MainLoop();

        std::list<InputType> _input;

        std::mutex _mutex;
        ThreadMessage _msg;
        Renderer _renderer;
    };
}

#endif // APPLICATION_H
