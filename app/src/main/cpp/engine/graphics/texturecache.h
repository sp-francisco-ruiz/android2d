//
//  GetTextureCache.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include <map>
#include <string>
#include <functional>

#include "engine/graphics/texture.h"

namespace engine
{
    namespace graphics
    {
        class TextureCache
        {

        public:
            TextureCache();

            void SetLoadFunction(std::function<Texture*(const std::string&)> textureLoadingFunc);
            const TexturePtr& GetTexture(const std::string& name);
            bool AddTexture(const std::string& name);

        private:
            std::function<Texture*(const std::string&)> _textureLoadingFunc;
            std::map<std::string, TexturePtr> _texturePool;
            std::string _resourcesPath;

            TextureCache(const TextureCache& o) = delete;
        };
    }
}
#endif // TEXTURECACHE_H
