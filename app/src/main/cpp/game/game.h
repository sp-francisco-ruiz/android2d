//
// Created by fjruiz on 14/04/2017.
//

#ifndef GAME_H
#define GAME_H

#include <list>

#include "engine/platform/application.h"
#include "engine/graphics/scene.h"

namespace game
{
    class Game
    {
        public:
        Game();

        void Initialize(int width, int height);
        void ProcessInput(const std::list<engine::platform::Application::InputType>& events);
        void Update(float deltaSeconds);

        engine::graphics::Scene* GetCurrentScene();

        protected:
        float _width;
        float _height;
        float _playerVelocity;
        engine::graphics::SpriteNodePtr _sprite;
        engine::graphics::SpriteNodePtr _background;
        engine::graphics::ScenePtr _currentScene;
    };
}

#endif //GAME_H
