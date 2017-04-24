//
// Created by fjruiz.
//

#include "platform/texture.h"
#include "platform/renderer.h"

namespace platform
{
    Texture::Texture()
    : _valid(false)
    {
    }

    Texture::~Texture()
    {
    }

    void Texture::SetTextureName(const std::string& fileName)
    {
        _fileName = fileName;
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