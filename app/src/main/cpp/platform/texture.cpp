//
// Created by fjruiz on 15/04/2017.
//

#include "platform/texture.h"
#include "platform/renderer.h"

namespace platform
{
    Texture::Texture(const std::string& fileName)
    : _valid(false)
    , _fileName(fileName)
    {
    }

    Texture::~Texture()
    {
    }

    bool Texture::Valid() const
    {
        return _valid;
    }

    unsigned int Texture::GetId() const
    {
        return _id;
    }

    void Texture::Init(Renderer &renderer)
    {
        _id = static_cast<unsigned int>(renderer.GetTextureId(_fileName));
        _valid = _id != 0xdead;
    }

}