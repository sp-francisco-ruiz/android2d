//
// Created by fjruiz on 15/04/2017.
//

#include <string>
#include <thread>

#include "game/game.h"
#include "engine/platform/application.h"
#include "engine/utils/clock.h"
#include "engine/utils/logger.h"

const std::string LOG_TAG("Application");
namespace engine
{
    namespace platform
    {
        Application::Application()
        : _msg(ThreadMessage::NONE)
        , _running(false)
        , _texturesCache()
        {
        }

        Application& Application::GetSharedApp()
        {
            static Application sharedApp;
            return sharedApp;
        }

        void Application::Start()
        {
            LOG_INFO("S");
            if(!_running)
            {
                _running = true;
                LOG_INFO("A");
                std::thread thread(std::bind(&Application::MainLoop, this));
                thread.detach();
            }
        }

        void Application::Resume()
        {

        }

        void Application::Pause()
        {

        }

        void Application::Stop() {
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
            _window.SetWindow(window);
            _msg = ThreadMessage::INITIALIZE;
            _mutex.unlock();
        }

        Application::~Application()
        {
        }

        void Application::MainLoop()
        {
            utils::Clock c;
            game::Game g;
            bool initialized = false;
            while (_running)
            {
                _mutex.lock();
                switch (_msg)
                {
                    case ThreadMessage::INITIALIZE:
                        if(!initialized)
                        {
                            _texturesCache.SetLoadFunction(std::bind(&Application::LoadTexture, this, std::placeholders::_1));
                            _window.Init();
                            g.Initialize(static_cast<int>(_window.GetWidth()), static_cast<int>(_window.GetHeight()));
                            c.Reset();
                            initialized = true;
                        }
                        break;

                    case ThreadMessage::EXIT:
                        _running = false;
                        _window.Dispose();
                        break;

                    default:
                        break;
                }
                _msg = ThreadMessage::NONE;
                if (initialized)
                {
                    LOG_INFO("Initialized A");
                    g.ProcessInput(_input);
                    _input.clear();
                    LOG_INFO("Initialized B");
                    g.Update(c.Seconds());
                    c.Reset();
                    ;
                    LOG_INFO("Initialized C");
                    _window.RenderScene(g.GetCurrentScene());
                    LOG_INFO("Initialized context");
                }
                _mutex.unlock();
            }

            return;
        }

        void Application::SetAssets(AAssetManager *assets)
        {
            _mutex.lock();
            _window.SetAssets(assets);
            _mutex.unlock();
        }

        graphics::TextureCache& Application::GetTextureCache()
        {
            return _texturesCache;
        }

        graphics::Texture *Application::LoadTexture(const std::string& name)
        {
            return _window.LoadTexture(name);
        }

        graphics::IWindow &Application::GetWindow()
        {
            return _window;
        }
    }
}