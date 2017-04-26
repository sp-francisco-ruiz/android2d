//
// Created by fjruiz.
//
#ifndef GAME_H
#define GAME_H

#include <list>

#include "game/player.h"
#include "game/obstacle.h"
#include "engine/igame.h"
#include "engine/application.h"
#include "engine/statictypes.h"
#include "utils/floatrandomset.h"

namespace game
{
    class Game : public engine::IGame
    {
        public:

        static const size_t kMaxPipes;
        static const float kPipesGap;
        static const float kObstacleWidth;
        static const float kObstacleHeight;
        static const float kFontSize;

        Game();

        void Initialize(int width, int height) override;
        void ProcessInput(const std::list<engine::InputType>& events) override;
        void Update(float deltaSeconds) override;
        void Draw(engine::IRenderer& renderer) override;
        void Dispose() override;

        protected:

        void CreatePipeAt(size_t id, float x);
        void UpdatePipePosition(size_t id, float delta);
        void UpdateScore(int value);
        void StartGame();

        int _score;
        float _pipesSpace;
        bool _waitingStart;
        float _playerX;
        float _width;
        float _height;
        float _playerVelocity;
        float _gameVelocity;
        Player _player;
        Obstacle _obstacles[4];
        engine::Sprite _background;
        engine::Sprite _startButton;
        utils::FloatRandomSet _rand;
        engine::Sprite _numbers[10];
    };
}

#endif //GAME_H
