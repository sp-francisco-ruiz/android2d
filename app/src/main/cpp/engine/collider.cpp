//
// Created by fjruiz.
//

#include "engine/collider.h"

namespace engine
{
    Collider::Collider()
    :_position(0.0f,0.0f,0.0f,1.0f)
    {
    }

    const utils::Vec4& Collider::GetPosition() const
    {
        return _position;
    }

    void Collider::SetPosition(float x, float y)
    {
        _position[0] = x;
        _position[1] = y;
    }
}