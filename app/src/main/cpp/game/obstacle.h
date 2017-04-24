//
// Created by fjruiz.
//
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "engine/circlecollider.h"
#include "engine/rectcollider.h"
#include "engine/sprite.h"

namespace game
{
    class Obstacle
    {
    public:
        Obstacle();
        void SetSize(float width, float height);
        float GetWidth() const;

        void SetPosition(float x, float y);
        const utils::Vec4& GetPosition() const;

        bool CollidesWith(const engine::CircleCollider& other);

        engine::Sprite& GetTopSprite();
        engine::Sprite& GetBottomSprite();
        engine::RectCollider& GetTopCollider();
        engine::RectCollider& GetBottomCollider();

    protected:
        engine::Sprite _topSprite;
        engine::Sprite _botSprite;
        engine::RectCollider _topCollider;
        engine::RectCollider _botCollider;
        utils::Vec4 _position;
    };
}

#endif //PLAYER_H
