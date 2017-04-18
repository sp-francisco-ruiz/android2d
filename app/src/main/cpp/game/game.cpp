//
// Created by fjruiz on 14/04/2017.
//

#include <cmath>
#include <string>

#include "game/game.h"
#include "utils/logger.h"

const std::string LOG_TAG("Game");

constexpr float G = -9.8f * 200.0f;
constexpr  float kImpulse = 700.0f;

namespace game
{
    Game::Game()
    :_background("squared.png")
    ,_sprite("rounded.png")
    {
    }

    void Game::Initialize(int width, int height)
    {
        _width = static_cast<float>(width);
        _height = static_cast<float>(height);
        _sprite.SetSize(100.0f, 100.0f);
        _sprite.SetPosition(_width/2, _height/2);
        _sprite.SetDepth(1.0f);

        _background.SetSize(width, height);
        _background.SetPosition(_width/2, _height/2);
        _background.SetDepth(2.0f);
        _playerVelocity = kImpulse;
    }

    void Game::Update(float deltaSeconds)
    {
        float newY = _sprite.GetPosition().y() + _playerVelocity * deltaSeconds + 0.5f * G * deltaSeconds * deltaSeconds;
        _playerVelocity += deltaSeconds * G;
        _sprite.SetPosition(_sprite.GetPosition().x(), newY);

        if(deltaSeconds > 0.1f)
        {
            LOG_ERROR("large delta %f", deltaSeconds);
        }
    }

    void Game::Draw(platform::Renderer &renderer)
    {
        renderer.DrawSprite(_background);
        renderer.DrawSprite(_sprite);
    }

    void Game::ProcessInput(const std::list<platform::Application::InputType>& events)
    {
        for(auto itr = events.begin(); itr != events.end(); ++itr)
        {
            switch((*itr))
            {
                case platform::Application::InputType::BEGIN:
                    _playerVelocity = kImpulse;
                break;
                case platform::Application::InputType::END:
                break;
            }
        }
    }
}