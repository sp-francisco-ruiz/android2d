//
// Created by fjruiz on 14/04/2017.
//
#include <string>

#include "engine/utils/vec4.h"
#include "engine/utils/mat4.h"
#include "engine/graphics/sprite.h"

namespace engine
{
    Sprite::Sprite(const std::string& fileName)
    :_width(0.0f)
    ,_height(0.0f)
    ,_position(0.0f,0.0f,0.0f,1.0f)
    ,_color(1.0f,1.0f,1.0f,1.0f)
    ,_texture()
    {
        _transform.LoadIdentity();
    }

    const utils::Vec4& Sprite::GetPosition() const
    {
        return _position;
    }

    void Sprite::SetPosition(float x, float y)
    {
        _position[0] = x;
        _position[1] = y;
        _transform.Translate(x, y, 0.0f);
    }

    void Sprite::SetDepth(float z)
    {
        _position[3] = z;
    }

    float Sprite::GetDepth() const
    {
        return _position.z();
    }

    void Sprite::SetSize(float width, float height)
    {
        _width = width;
        _height = height;
        _transform.Scale(_width, _height, 1.0f);
    }

    float Sprite::GetWidth() const
    {
        return _width;
    }

    float Sprite::GetHeight() const
    {
        return _height;
    }

    const utils::Mat4& Sprite::GetTransform() const
    {
        return _transform;
    }

    const graphics::TexturePtr& Sprite::GetTexture()
    {
        return _texture;
    }
}