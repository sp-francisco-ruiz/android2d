//
// Created by fjruiz on 16/04/2017.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include <mutex>
#include <list>

namespace platform
{
    class Renderer;

    class Texture
    {
    public:

        Texture(const std::string& fileName);
        ~Texture();

        bool Valid() const;
        unsigned int GetId() const;

        void Init(Renderer& renderer);

    private:
        std::string _fileName;
        bool _valid;
        unsigned int _id;
    };
}

#endif // TEXTURE_H
