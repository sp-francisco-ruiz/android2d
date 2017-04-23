//
//  GetTextureCache.cpp
//
//  Created by Francisco Ruiz.
//
//

#include <cassert>

#include "engine/graphics/texturecache.h"


namespace engine
{
    namespace graphics
    {

        TextureCache::TextureCache()
        {
            AddTexture("Icon.png");
        }

        void TextureCache::SetLoadFunction(std::function<Texture *(const std::string &)> textureLoadingFunc)
        {
            _textureLoadingFunc = textureLoadingFunc;
        }

        const TexturePtr& TextureCache::GetTexture(const std::string& name)
        {
            if (_texturePool.count(name))
            {
                return _texturePool.at(name);
            }

            if (AddTexture(name))
            {
                return _texturePool.at(name);
            }

            assert(false && "Trying to load an unexistent texture file");
            return _texturePool.at("default.png");
        }

        bool TextureCache::AddTexture(const std::string& name)
        {
            if (_texturePool.count(name))
            {
                return true;
            }
            if(_textureLoadingFunc)
            {
                Texture* texture = _textureLoadingFunc(name);
                if (!texture)
                {
                    return false;
                }
                std::pair<std::string, TexturePtr> pair(name, texture);
                _texturePool.insert(pair);
                return true;
            }
            return false;
        }
    }
}