//
// Created by fjruiz on 14/04/2017.
//

#ifndef COLLIDER_H
#define COLLIDER_H

#include "utils/vec4.h"
namespace engine
{
    class Collider
    {
    public:
        enum class Shape
        {
            Circle = 0,
            Rect
        };

        Collider();

        const utils::Vec4& GetPosition() const;
        void SetPosition(float x, float y);

        void SetSize(float width, float height);

        float GetWidth() const;
        float GetHeight() const;

        float GetRadius() const;
        void SetRadius(float radius);

        Shape GetShape() const;

        bool CollidesWith(const Collider& other) const;

    protected:

        static bool CheckCircleCircle(const Collider& a, const Collider& b);
        static bool CheckCircleRect(const Collider &circle, const Collider &square);
        static bool CheckRectRect(const Collider &a, const Collider &b);
        static bool CheckPointRect(float px, float py, float rectMinX, float rectMinY, float rectMaxX, float rectMaxY);
        static float ClosestDistanceInSegmentToPointSq(float fromX, float fromY, float toX, float toY, float px, float py);

        Shape _shape;
        float _width;
        float _height;
        float _radius;
        utils::Vec4 _position;
    };
}

#endif //COLLIDER_H
