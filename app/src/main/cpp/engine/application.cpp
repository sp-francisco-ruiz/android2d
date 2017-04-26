//
// Created by fjruiz.
//
#include <string>
#include <thread>

#include "engine/application.h"
#include "engine/ifilesmanager.h"
#include "engine/iwindow.h"
#include "engine/irenderer.h"
#include "engine/igame.h"
#include "utils/clock.h"

namespace engine
{
    Application& Application::GetInstance()
    {
        static Application sharedApp;
        return sharedApp;
    }

    Application::Application()
    : _msg(ThreadMessage::NONE)
    {
    }

    Application::~Application()
    {
    }

    void Application::SetWindow(IWindow* window)
    {
        _mutex.lock();
        _window.reset(window);
        _msg = ThreadMessage::INITIALIZE;
        _mutex.unlock();
    }

    void Application::SetGame(IGame* game)
    {
        _mutex.lock();
        _game.reset(game);
        _mutex.unlock();
    }

    void Application::SetFilesManager(IFilesManager* fmanager)
    {
        _mutex.lock();
        _filesManager.reset(fmanager);
        _mutex.unlock();
    }

    IFilesManager& Application::GetFilesManager()
    {
        return *_filesManager;
    }

    IWindow& Application::GetWindow()
    {
        return *_window;
    }

    void Application::Start()
    {
        std::thread thread(std::bind(&Application::MainLoop, this));
        thread.detach();
    }

    void Application::Stop()
    {
        _mutex.lock();
        _msg = ThreadMessage::EXIT;
        _mutex.unlock();
    }

    void Application::OnPressed()
    {
        _input.push_back(InputType::BEGIN);
    }

    void Application::MainLoop()
    {
        bool exit = false;
        utils::Clock c;
        bool initialized = false;
        while (!exit)
        {
            _mutex.lock();
            IGame& game = *_game;

            switch (_msg)
            {
                case ThreadMessage::INITIALIZE:
                    _window->Initialize();
                    game.Initialize(_window->GetWidth(), _window->GetHeight());
                    c.Reset();
                    initialized = true;
                    break;

                case ThreadMessage::EXIT:
                    exit = true;
                    game.Dispose();
                    _window->Dispose();
                    break;

                default:
                    break;
            }
            _msg = ThreadMessage::NONE;
            if (initialized)
            {
                IRenderer& renderer = _window->GetRenderer();

                game.ProcessInput(_input);
                _input.clear();

                game.Update(c.Seconds());
                c.Reset();

                renderer.StartFrame();
                game.Draw(renderer);
                renderer.EndFrame();
            }
            _mutex.unlock();
        }

        return;
    }
}