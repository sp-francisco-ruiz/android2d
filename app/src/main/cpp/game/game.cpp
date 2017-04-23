//
// Created by fjruiz on 14/04/2017.
//

#include <cmath>
#include <string>

#include "game/game.h"
#include "engine/utils/logger.h"

#include "engine/physics/collider.h"

const std::string LOG_TAG("Game");

constexpr float G = -9.8f * 200.0f;
constexpr  float kImpulse = 700.0f;

engine::physics::Collider circle, rect;

namespace game
{
    Game::Game()
    {
    }

    void Game::Initialize(int width, int height)
    {
        _currentScene = engine::graphics::Scene::Create();
        _width = static_cast<float>(width);
        _height = static_cast<float>(height);
        _sprite = engine::graphics::SpriteNode::Create("rounded.png");
        _sprite->SetSize(engine::utils::Vec2(100.0f, 100.0f));
        _sprite->SetPosition(engine::utils::Vec2(_width/2, _height/2));
        _sprite->SetZOrder(1);

        _currentScene->AddChild(_sprite.get());

        _background = engine::graphics::SpriteNode::Create("squared.png");
        _background->SetSize(engine::utils::Vec2(width, height));
        _background->SetPosition(engine::utils::Vec2(_width/2, _height/2));
        _background->SetZOrder(2);
        _playerVelocity = kImpulse;

        _currentScene->AddChild(_background.get());

        circle.SetRadius(1000.0f);
        rect.SetSize(200.0f, 200.0f);
        circle.SetPosition(0.0f, 0.0f);
        rect.SetPosition(300.0f, 300.0f);
    }

    void Game::Update(float deltaSeconds)
    {
        float newY = _sprite->GetPosition().y() + _playerVelocity * deltaSeconds + 0.5f * G * deltaSeconds * deltaSeconds;
        _playerVelocity += deltaSeconds * G;
        _sprite->SetPosition(engine::utils::Vec2(_sprite->GetPosition().x(), newY));

        if(deltaSeconds > 0.1f)
        {
            LOG_ERROR("large delta %f", deltaSeconds);
        }
    }

    void Game::ProcessInput(const std::list<engine::platform::Application::InputType>& events)
    {
        for(auto itr = events.begin(); itr != events.end(); ++itr)
        {
            switch((*itr))
            {
                case engine::platform::Application::InputType::BEGIN:
                    _playerVelocity = kImpulse;
                break;
                case engine::platform::Application::InputType::END:
                break;
            }
        }
    }

    engine::graphics::Scene* Game::GetCurrentScene()
    {
        _currentScene.get();
    }
}