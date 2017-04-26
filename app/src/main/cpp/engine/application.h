//
// Created by fjruiz.
//
#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <mutex>
#include <list>

#include "engine/statictypes.h"

namespace engine
{
    class IGame;
    class IFilesManager;
    class IWindow;

    class Application
    {
    public:

        static Application& GetInstance();

        void Start();

        void Stop();

        void OnPressed();

        void SetGame(IGame* game);

        void SetWindow(IWindow* window);
        IWindow& GetWindow();

        void SetFilesManager(IFilesManager* fmanager);
        IFilesManager& GetFilesManager();

    private:

        Application();

        ~Application();

        enum class ThreadMessage
        {
            NONE = 0,
            INITIALIZE,
            EXIT
        };

        void MainLoop();

        std::list<InputType> _input;

        std::mutex _mutex;
        ThreadMessage _msg;

        std::unique_ptr<IGame> _game;
        std::unique_ptr<IFilesManager> _filesManager;
        std::unique_ptr<IWindow> _window;
    };
}

#endif // APPLICATION_H
