//
// Created by fjruiz.
//
#include <string>
#include <thread>

#include "game/game.h"
#include "utils/clock.h"

namespace platform
{
    Application::Application()
    : _msg(ThreadMessage::NONE)
    {
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

    void Application::SetWindow(ANativeWindow *window)
    {
        _mutex.lock();
        _renderer.SetWindow(window);
        _msg = ThreadMessage::INITIALIZE;
        _mutex.unlock();
    }

    Application::~Application()
    {
    }

    void Application::MainLoop()
    {
        bool exit = false;
        utils::Clock c;
        game::Game g;
        bool initialized = false;
        while (!exit)
        {
            _mutex.lock();
            switch (_msg)
            {
                case ThreadMessage::INITIALIZE:
                    _renderer.Initialize();
                    g.Initialize(_renderer.GetWidth(), _renderer.GetHeight());
                    c.Reset();
                    initialized = true;
                    break;

                case ThreadMessage::EXIT:
                    exit = true;
                    _renderer.Destroy();
                    break;

                default:
                    break;
            }
            _msg = ThreadMessage::NONE;
            if (initialized)
            {
                g.ProcessInput(_input);
                _input.clear();

                g.Update(c.Seconds());
                c.Reset();

                _renderer.StartFrame();
                g.Draw(_renderer);
                _renderer.EndFrame();
            }
            _mutex.unlock();
        }

        return;
    }

    void Application::SetAssets(AAssetManager *assets)
    {
        _mutex.lock();
        _renderer.SetAssetManager(assets);
        _mutex.unlock();
    }
}