//
// Created by fjruiz.
//

#include "engine/texture.h"
#include "engine/irenderer.h"

namespace engine
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

    void Texture::Init(engine::IRenderer& renderer)
    {
        _id = renderer.GetTextureId(_fileName);
        _valid = _id != 0xdead;
    }

}