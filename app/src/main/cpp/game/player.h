//
// Created by fjruiz.
//
#ifndef PLAYER_H
#define PLAYER_H

#include "engine/circlecollider.h"
#include "engine/sprite.h"

namespace game
{
    class Player
    {
        public:
        Player();
        void SetPosition(float x, float y);
        void SetSize(float width, float height);
        float GetWidth() const;
        float GetHeight() const;

        const utils::Vec4& GetPosition() const;
        const engine::CircleCollider& GetCollider() const;
        engine::Sprite& GetSprite();

        protected:
        engine::Sprite _sprite;
        engine::CircleCollider _collider;
    };
}

#endif //PLAYER_H
