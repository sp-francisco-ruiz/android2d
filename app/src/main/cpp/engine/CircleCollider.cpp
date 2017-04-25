//
// Created by Francisco Ruiz.
//

#include "engine/circlecollider.h"

namespace engine
{
    CircleCollider::CircleCollider()
    :_radius(0.0f)
    {
    }

    float CircleCollider::GetRadius() const
    {
        return _radius;
    }

    void CircleCollider::SetRadius(float radius)
    {
        _radius = radius;
    }
}