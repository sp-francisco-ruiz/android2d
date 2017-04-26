//
// Created by fjruiz.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

namespace engine
{
    class IRenderer;
    class Texture
    {
    public:

        Texture();
        void SetTextureName(const std::string& fileName);
        ~Texture();

        bool Valid() const;
        unsigned int GetId() const;

        void Init(IRenderer& renderer);

    private:
        std::string _fileName;
        bool _valid;
        unsigned int _id;
    };
}

#endif // TEXTURE_H
