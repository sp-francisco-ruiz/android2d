//
// Created by fjruiz.
//

#include <limits>
#include <algorithm>

#include "engine/physics.h"

namespace engine
{
    bool Physics::Overlaps(const CircleCollider& a, const CircleCollider& b)
    {
        float radius = a.GetRadius() + b.GetRadius();
        utils::Vec4 distance = a.GetPosition() - b.GetPosition();
        return distance.LengthSq() < radius * radius;
    }

    bool Physics::Overlaps(const CircleCollider& a, RectCollider& b)
    {
        return CheckCircleRect(a, b);
    }

    bool Physics::Overlaps(RectCollider& a, const CircleCollider& b)
    {
        return CheckCircleRect(b, a);
    }

    bool Physics::Overlaps(RectCollider& a, RectCollider& b)
    {
        return Overlaps(a.GetAABB(), b.GetAABB());
    }
    bool Physics::Overlaps(const utils::Vec4& aabb1, const utils::Vec4& aabb2)
    {
        return !( aabb1[2] < aabb2[0] || //maxX < minX
                  aabb1[0] > aabb2[2] || //minX > maxX
                  aabb1[3] < aabb2[1] || //maxY < minY
                  aabb1[1] > aabb2[3]);  //minY > maxY
    }

    bool Physics::CheckCircleRect(const CircleCollider& circle, RectCollider& rect)
    {
        float px = circle.GetPosition().x();
        float py = circle.GetPosition().y();
        float radius = circle.GetRadius();

        utils::Vec4 rectAABB = rect.GetAABB();
        utils::Vec4 circleAABB(px - radius, py - radius, px + radius, py + radius);
        if(!Overlaps(rectAABB, circleAABB))
            return false;

        float rectMinX = rectAABB[0];
        float rectMinY = rectAABB[1];
        float rectMaxX = rectAABB[2];
        float rectMaxY = rectAABB[3];

        // center is inside the square
        if(CheckPointRect(px, py, rect))
            return true;

        float sqRadius = radius * radius;
        return ClosestDistanceInSegmentToPointSq(rectMinX, rectMinY, rectMaxX, rectMinY, px, py) < sqRadius || // 00->10
               ClosestDistanceInSegmentToPointSq(rectMaxX, rectMinY, rectMaxX, rectMaxY, px, py) < sqRadius || // 10->11
               ClosestDistanceInSegmentToPointSq(rectMaxX, rectMaxY, rectMinX, rectMaxY, px, py) < sqRadius || // 11->01
               ClosestDistanceInSegmentToPointSq(rectMinX, rectMaxY, rectMinX, rectMinY, px, py) < sqRadius;   // 01->00
    }

    bool Physics::CheckPointRect(float px, float py, RectCollider& rect)
    {
        return !( px < rect.GetAABB()[0] ||
                  px > rect.GetAABB()[2] ||
                  py < rect.GetAABB()[1] ||
                  py > rect.GetAABB()[3]);
    }

    float Physics::ClosestDistanceInSegmentToPointSq(float fromX, float fromY, float toX, float toY, float px, float py)
    {
        float lineX = toX - fromX;
        float lineY = toY - fromY;

        float tocircleX = px - fromX;
        float tocircleY = py - fromY;

        float sqlength = lineX * lineX + lineY * lineY;

        if (sqlength < std::numeric_limits<float>::epsilon())
            return tocircleX * tocircleX + tocircleY * tocircleY;

        float dot = tocircleX * lineX + tocircleY * lineY;
        float f = dot / sqlength;
        f = std::max<float>(0.0f, std::min<float>(1.0f, f));
        float projX = fromX + f * lineX;
        float projY = fromY + f * lineY;

        float projToCiorcleX = px - projX;
        float projToCiorcleY = py - projY;

        return projToCiorcleX * projToCiorcleX + projToCiorcleY * projToCiorcleY;


    }
}