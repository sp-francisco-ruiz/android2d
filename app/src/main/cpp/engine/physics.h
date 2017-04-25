//
// Created by fjruiz.
//

#ifndef PHYSICS_H
#define PHYSICS_H

#include "engine/circlecollider.h"
#include "engine/rectcollider.h"

namespace engine
{
    class Physics
    {
    public:

        static bool Overlaps(const CircleCollider& a, const CircleCollider& b);
        static bool Overlaps(const CircleCollider& a, RectCollider& b);
        static bool Overlaps(RectCollider& a, const CircleCollider& b);
        static bool Overlaps(RectCollider& a, RectCollider& b);
        static bool Overlaps(const utils::Vec4& aabb1, const utils::Vec4& aabb2);

        static bool CheckCircleRect(const CircleCollider &circle, RectCollider &square);
        static bool CheckPointRect(float px, float py, RectCollider& r);
        static float ClosestDistanceInSegmentToPointSq(float fromX, float fromY, float toX, float toY, float px, float py);
    };
}

#endif //PHYSICS_H
