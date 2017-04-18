//
// Created by fjruiz on 14/04/2017.
//

#ifndef GAME_H
#define GAME_H

#include <list>

#include "platform/application.h"
#include "engine/sprite.h"

namespace game
{
    class Game
    {
        public:
        Game();

        void Initialize(int width, int height);
        void ProcessInput(const std::list<platform::Application::InputType>& events);
        void Update(float deltaSeconds);
        void Draw(platform::Renderer& renderer);

        protected:
        float _width;
        float _height;
        float _playerVelocity;
        engine::Sprite _sprite;
        engine::Sprite _background;
    };
}

#endif //GAME_H
