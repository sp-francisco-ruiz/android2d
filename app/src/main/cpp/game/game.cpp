//
// Created by fjruiz.
//
#include <cmath>
#include <string>
#include <sstream>

#include "game/game.h"
#include "utils/logger.h"

const std::string LOG_TAG("Game");

constexpr float G = -9.8f * 200.0f;
constexpr  float kImpulse = 700.0f;


namespace game
{
    const size_t Game::kMaxPipes = 4;
    const float Game::kPipesGap = 200.0f;
    const float Game::kObstacleWidth = 200.0f;
    const float Game::kObstacleHeight = 1100.0f;
    const float Game::kFontSize = 50.0f;

    Game::Game()
    :_rand(0.0f, 1.0f)
    {
        _waitingStart = false;
    }

    void Game::Initialize(int width, int height)
    {
        _width = static_cast<float>(width);
        _height = static_cast<float>(height);

        for(int i = 0; i < kMaxPipes; ++i)
        {
            _obstacles[i].SetSize(kObstacleWidth, kObstacleHeight);
        }
        _startButton.SetTexture("start.png");
        _startButton.SetSize(300.0f, 200.0f);
        _startButton.SetPosition(width * 0.5f, height * 0.5f);
        _startButton.SetDepth(4.0f);

        _background.SetTexture("bg.png");
        _background.SetSize(width, height);
        _background.SetPosition(width * 0.5f, height * 0.5f);
        _background.SetDepth(1.0f);

        _player.SetSize(100.0f, 100.0f);

        for(int i = 0; i < 10; ++i)
        {
            std::stringstream ss;
            ss << "n" << i << ".png";
            _numbers[i].SetTexture(ss.str());
            _numbers[i].SetSize(kFontSize, kFontSize);
            _numbers[i].SetDepth(4.0f);
        }
    }

    void Game::StartGame()
    {
        _waitingStart = true;
        _playerVelocity = kImpulse;
        float halfHeight = _height * 0.5f;

        _pipesSpace = _width;
        _gameVelocity = 180.0f;

        _playerX = _width * 0.33f;
        _player.SetPosition(_playerX, halfHeight);

        for(size_t i = 0; i < kMaxPipes; ++i)
        {
            CreatePipeAt(i, _width + _pipesSpace * i);
        }
        UpdateScore(0);
    }

    void Game::Update(float deltaSeconds)
    {
        if(_waitingStart)
        {
            return;
        }
        float newY = _player.GetPosition().y() + _playerVelocity * deltaSeconds + 0.5f * G * deltaSeconds * deltaSeconds;
        _playerVelocity += deltaSeconds * G;
        _player.SetPosition(_playerX, newY);

        float obstaclesDisplacement = -deltaSeconds * _gameVelocity;
        for(size_t i = 0; i < kMaxPipes; ++i)
        {
            UpdatePipePosition(i, obstaclesDisplacement);
            if(_obstacles[i].CollidesWith(_player.GetCollider()))
            {
                StartGame();
                return;
            }
        }
        if(_player.GetPosition().y() < _player.GetHeight() * 0.5f ||
           _player.GetPosition().y() > _height - _player.GetHeight() * 0.5f)
        {
            StartGame();
        }
        _gameVelocity += _gameVelocity * 0.001f * deltaSeconds;
    }

    void Game::Draw(platform::Renderer &renderer)
    {
        renderer.DrawSprite(_background);
        for(size_t i = 0; i < kMaxPipes; ++i)
        {
            renderer.DrawSprite(_obstacles[i].GetTopSprite());
            renderer.DrawSprite(_obstacles[i].GetBottomSprite());
        }
        renderer.DrawSprite(_player.GetSprite());
        if(_waitingStart)
        {
            renderer.DrawSprite(_startButton);
        }

        int first = _score % 10;
        _numbers[first].SetPosition(_width - kFontSize, _height - kFontSize);
        renderer.DrawSprite(_numbers[first]);

        int second = (_score / 10) % 10;
        if(second > 0)
        {
            _numbers[second].SetPosition(_width - kFontSize * 2.0f, _height - kFontSize);
            renderer.DrawSprite(_numbers[second]);
        }
        int third = (_score / 100) % 10;
        if(third > 0)
        {
            _numbers[third].SetPosition(_width - kFontSize * 3.0f, _height - kFontSize);
            renderer.DrawSprite(_numbers[third]);
        }
    }

    void Game::ProcessInput(const std::list<platform::Application::InputType>& events)
    {
        for(auto itr = events.begin(); itr != events.end(); ++itr)
        {
            switch((*itr))
            {
                case platform::Application::InputType::BEGIN:
                    _waitingStart = false;
                    _playerVelocity = kImpulse;
                break;
                case platform::Application::InputType::END:
                break;
            }
        }
    }

    void Game::CreatePipeAt(size_t id, float x)
    {
        float y = kPipesGap * 2 + _rand.GetNext() * (_height - kPipesGap * 4);
        _obstacles[id].SetPosition(x, y);
    }

    void Game::UpdatePipePosition(size_t id, float delta)
    {
        float x = _obstacles[id].GetPosition().x() + delta;
        _obstacles[id].SetPosition(x, _obstacles[id].GetPosition().y());

        if(x < _width * 0.5f && x - delta > _width * 0.5f)
        {
            UpdateScore(_score+1);
        }

        if(x < -kObstacleWidth * 0.5f)
        {
            CreatePipeAt(id, _width + _pipesSpace * (kMaxPipes - 1));
        }
    }

    void Game::UpdateScore(int value)
    {
        _score = value;
        if(_score > 0 && _score % 5 == 0)
        {
            _pipesSpace = _pipesSpace * 0.9f;
        }
    }
}