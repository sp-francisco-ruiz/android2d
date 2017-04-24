//
// Created by fjruiz.
//

#include "engine/physics.h"
#include "game/obstacle.h"
#include "game/game.h"

namespace game
{

    Obstacle::Obstacle()
    {
        _topSprite.SetTexture("pipetop.png");
        _botSprite.SetTexture("pipebottom.png");
        _botSprite.SetDepth(2.0f);
        _topSprite.SetDepth(2.0f);
    }

    void Obstacle::SetPosition(float x, float y)
    {
        _position[0] = x;
        _position[1] = y;

        float topY = y + Game::kPipesGap + Game::kObstacleHeight * 0.5f;
        float botY = y - Game::kPipesGap - Game::kObstacleHeight * 0.5f;

        _topSprite.SetPosition(x, topY);
        _topCollider.SetPosition(x, topY);
        _botSprite.SetPosition(x, botY);
        _botCollider.SetPosition(x, botY);
    }

    void Obstacle::SetSize(float width, float height)
    {
        _topSprite.SetSize(width, height);
        _topCollider.SetSize(width, height);
        _botSprite.SetSize(width, height);
        _botCollider.SetSize(width, height);
    }

    engine::Sprite& Obstacle::GetTopSprite()
    {
        return _topSprite;
    }

    engine::Sprite& Obstacle::GetBottomSprite()
    {
        return _botSprite;
    }

    const utils::Vec4& Obstacle::GetPosition() const
    {
        return _position;
    }

    float Obstacle::GetWidth() const
    {
        return _topSprite.GetWidth();
    }

    bool Obstacle::CollidesWith(const engine::CircleCollider& other)
    {
        return engine::Physics::Overlaps(other, _topCollider) ||
               engine::Physics::Overlaps(other, _botCollider);
    }

    engine::RectCollider& Obstacle::GetTopCollider()
    {
        return _topCollider;
    }

    engine::RectCollider& Obstacle::GetBottomCollider()
    {
        return _botCollider;
    }
}