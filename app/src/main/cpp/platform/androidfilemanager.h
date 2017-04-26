//
// Created by fjruiz.
//
#ifndef ANDROIDFILEMANAGER_H
#define ANDROIDFILEMANAGER_H

#include "engine/ifilesmanager.h"

class AAssetManager;

namespace platform
{
    class AndroidFileManager : public engine::IFilesManager
    {

    public:
        AndroidFileManager();

        void SetAssetManager(AAssetManager* assetManager);

        //allocated memory must be freed
        unsigned char* GetFileContents(const std::string& file, unsigned int& outSize);

    private:
        AAssetManager *_assetManager;
    };
}
#endif // ANDROIDFILEMANAGER_H