//
// Created by fjruiz on 14/04/2017.
//

#include <cmath>
#include <limits>

#include "engine/collider.h"

namespace engine
{
    Collider::Collider()
    :_width(0.0f)
    ,_height(0.0f)
    ,_radius(0.0f)
    ,_position(0.0f,0.0f,0.0f,1.0f)
    ,_shape(Shape::Circle)
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

    void Collider::SetSize(float width, float height)
    {
        _width = width;
        _height = height;
        _radius = 0.0f;
        _shape = Shape::Rect;
    }

    float Collider::GetWidth() const
    {
        return _width;
    }

    float Collider::GetHeight() const
    {
        return _height;
    }

    float Collider::GetRadius() const
    {
        return _radius;
    }
    void Collider::SetRadius(float radius)
    {
        _width = 0.0f;
        _height = 0.0f;
        _radius = radius;
        _shape = Shape::Circle;
    }

    Collider::Shape Collider::GetShape() const
    {
        return _shape;
    }

    bool Collider::CollidesWith(const Collider& other) const
    {
        //given the game type a circle will always be colliding rects, ideally this should be done by inheritance
        if(GetShape() == Shape::Circle && other.GetShape() == Shape::Rect)
        {
            return CheckCircleRect(*this, other);
        }
        else if(GetShape() == Shape::Rect && other.GetShape() == Shape::Circle)
        {
            return CheckCircleRect(other, *this);
        }
        else if(GetShape() == Shape::Rect && other.GetShape() == Shape::Rect)
        {
            return CheckRectRect(other, *this);
        }
        else if(GetShape() == Shape::Circle && other.GetShape() == Shape::Circle)
        {
            return CheckCircleCircle(*this, other);
        }

        return false;
    }


    bool Collider::CheckCircleCircle(const Collider& a, const Collider& b)
    {
        float radius = a._radius + b._radius;
        utils::Vec4 distance = a._position - b._position;
        return distance.LengthSq() < radius * radius;
    }

    bool Collider::CheckCircleRect(const Collider &circle, const Collider &square)
    {
        float px = circle._position.x();
        float py = circle._position.y();

        float rectMinX = square._position.x();
        float rectMinY = square._position.y();
        float rectMaxX = square._position.x() + square._width;
        float rectMaxY = square._position.y() + square._height;

        // center is inside the square
        if(CheckPointRect(px, py, rectMinX, rectMinY, rectMaxX, rectMaxY))
            return true;

        float sqRadius = circle._radius * circle._radius;
        return ClosestDistanceInSegmentToPointSq(rectMinX, rectMinY, rectMaxX, rectMinY, px, py) < sqRadius || // 00->10
               ClosestDistanceInSegmentToPointSq(rectMaxX, rectMinY, rectMaxX, rectMaxY, px, py) < sqRadius || // 10->11
               ClosestDistanceInSegmentToPointSq(rectMaxX, rectMaxY, rectMinX, rectMaxY, px, py) < sqRadius || // 11->01
               ClosestDistanceInSegmentToPointSq(rectMinX, rectMaxY, rectMinX, rectMinY, px, py) < sqRadius;   // 01->00
    }

    bool Collider::CheckRectRect(const Collider &a, const Collider &b)
    {
        return !( a._position.x() + a._width < b._position.x() ||
                  a._position.x() > b._position.x() + b._width ||
                  a._position.y() + a._height < b._position.y()||
                  a._position.y() > b._position.y() + b._height);
    }

    bool Collider::CheckPointRect(float px, float py, float rectMinX, float rectMinY, float rectMaxX, float rectMaxY)
    {
        return !( px < rectMinX ||
                  px > rectMaxX ||
                  py < rectMinY ||
                  py > rectMaxY);
    }

    float Collider::ClosestDistanceInSegmentToPointSq(float fromX, float fromY, float toX, float toY, float px, float py)
    {
        float l2 = (toX - fromX) * (toX - fromX) + (toY - fromY) * (toY - fromY); // lengthSq

        if (l2 < std::numeric_limits<float>::epsilon())
            return (toX - px) * (toX - px) + (toY - px) * (toY - px); //to and from are the same point

        float t = ((px - fromX) * (toX - fromX) + (py - fromY) * (toY - fromY)) / l2; // project the point on the line
        t = fmaxf(0.0f, fminf(1.0f, t)); // clamp it to 0-1
        float projX = fromX + t * (toX - fromX);
        float projY = fromY + t * (toY - fromY);
        // return the squared length between the closest point in the line and the target point
        return (projX - px) * (projX - px) + (projY - px) * (projY - px);
    }
}