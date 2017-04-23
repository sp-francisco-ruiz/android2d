//
// Created by fjruiz on 14/04/2017.
//

#ifndef SPRITE_H
#define SPRITE_H

#include "engine/utils/mat4.h"
#include "engine/graphics/texture.h"

namespace engine
{
    class Sprite
    {
    public:
        Sprite(const std::string& fileName);

        const utils::Vec4& GetPosition() const;
        void SetPosition(float x, float y);
        void SetDepth(float z);
        float GetDepth() const;

        void SetSize(float width, float height);

        float GetWidth() const;
        float GetHeight() const;
        const utils::Mat4& GetTransform() const;

        const graphics::TexturePtr& GetTexture();

    protected:
        float _width;
        float _height;
        utils::Vec4 _position;
        utils::Vec4 _color;
        utils::Mat4 _transform;
        graphics::TexturePtr _texture;
    };
}

#endif //SPRITE_H
