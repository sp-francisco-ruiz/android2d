//
// Created by fjruiz on 16/04/2017.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "engine/utils/referenced.h"
#include "engine/utils/vec2.h"

namespace engine
{
    namespace graphics
    {
        class Texture : public utils::Referenced
        {

        public:
            float GetWidth() const;
            float GetHeight() const;
            unsigned int GetId() const;
            const utils::Vec2& GetSize() const;
            const std::string& GetName() const;

            Texture(const std::string& name, unsigned int id);
            virtual ~Texture();

        protected:
            Texture(const Texture&) = delete;
            Texture& operator=(const Texture&) = delete;

            std::string _name;
            utils::Vec2 _size;
            unsigned int _id;
        };
        typedef utils::ref_ptr<Texture> TexturePtr;
    }
}
#endif // TEXTURE_H
