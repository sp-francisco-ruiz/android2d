//
// Created by fjruiz.
//
#ifndef IFILESMANAGER_H
#define IFILESMANAGER_H

#include <string>

namespace engine
{
    class IFilesManager
    {

    public:

        virtual unsigned char* GetFileContents(const std::string& file, unsigned int& outSize) = 0;
    };
}
#endif // IFILESMANAGER_H