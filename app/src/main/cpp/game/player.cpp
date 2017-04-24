//
// Created by fjruiz.
//

#include "game/player.h"

namespace game
{

    Player::Player()
    {
        _sprite.SetTexture("bird.png");
        _sprite.SetDepth(3.0f);
    }

    void Player::SetPosition(float x, float y)
    {
        _sprite.SetPosition(x, y);
        _collider.SetPosition(x, y);
    }

    void Player::SetSize(float width, float height)
    {
        _sprite.SetSize(width, height);
        _collider.SetRadius(width * 0.25f);
    }

    const engine::CircleCollider& Player::GetCollider() const
    {
        return _collider;
    }

    engine::Sprite& Player::GetSprite()
    {
        return _sprite;
    }

    const utils::Vec4& Player::GetPosition() const
    {
        return _sprite.GetPosition();
    }

    float Player::GetWidth() const
    {
        return _sprite.GetWidth();
    }

    float Player::GetHeight() const
    {
        return _sprite.GetHeight();
    }
}