//
// Created by fjruiz.
//

#include "engine/texture.h"
#include "engine/irenderer.h"
#include "engine/iwindow.h"
#include "engine/application.h"

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
        Init();
    }

    bool Texture::Valid() const
    {
        return _valid;
    }

    unsigned int Texture::GetId() const
    {
        return _id;
    }

    void Texture::Init()
    {
        _id = Application::GetInstance().GetWindow().GetRenderer().GetTextureId(_fileName);
        _valid = _id != 0xdead;
    }

}