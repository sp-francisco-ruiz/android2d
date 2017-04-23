//
// Created by fjruiz on 15/04/2017.
//

#include "engine/graphics/texture.h"

namespace engine
{
    namespace graphics
    {
        float Texture::GetWidth() const
        {
            return _size.x();
        }

        float Texture::GetHeight() const
        {
            return _size.y();
        }

        unsigned int Texture::GetId() const
        {
            return _id;
        }

        const utils::Vec2& Texture::GetSize() const
        {
            return _size;
        }

        const std::string& Texture::GetName() const
        {
            return _name;
        }

        Texture::Texture(const std::string& name, unsigned int id)
        :_name(name)
        , _id(id)
        {

        }

        Texture::~Texture()
        {

        }
    }
}