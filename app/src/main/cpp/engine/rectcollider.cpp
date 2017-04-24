//
// Created by Francisco Ruiz.
//

#include "engine/rectcollider.h"

namespace engine
{
    RectCollider::RectCollider()
    :_width(0.0f)
    ,_height(0.0f)
    ,_dirty(false)
    {

    }

    void RectCollider::SetSize(float width, float height)
    {
        _width = width;
        _height = height;
        _dirty = true;
    }

    float RectCollider::GetWidth() const
    {
        return _width;
    }

    float RectCollider::GetHeight() const
    {
        return _height;
    }
    const utils::Vec4& RectCollider::GetAABB()
    {
        if (_dirty)
        {
            _aabb = utils::Vec4(_position.x() - _width * 0.5f,
                                _position.y() - _height * 0.5f,
                                _position.x() + _width * 0.5f,
                                _position.y() + _height * 0.5f);
            _dirty = false;
        }
        return _aabb;
    }

    void RectCollider::SetPosition(float x, float y)
    {
        _position[0] = x;
        _position[1] = y;
        _dirty = true;
    }
}