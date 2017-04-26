//
// Created by fjruiz.
//

#include <android/asset_manager.h>
#include "platform/androidfilemanager.h"

namespace platform
{
    AndroidFileManager::AndroidFileManager()
    : _assetManager(nullptr)
    {
    }

    void AndroidFileManager::SetAssetManager(AAssetManager* assetManager)
    {
        _assetManager = assetManager;
    }

    unsigned char* AndroidFileManager::GetFileContents(const std::string& file, unsigned int& outSize)
    {
        outSize = 0;
        if(!_assetManager)
        {
            return nullptr;
        }

        auto asset = AAssetManager_open(_assetManager, file.c_str(), AASSET_MODE_UNKNOWN);
        if(!asset)
        {
            return nullptr;
        }
        outSize = static_cast<size_t>(AAsset_getLength(asset));
        unsigned char* rawData = static_cast<unsigned char*>(malloc (sizeof(char)*outSize));
        AAsset_read (asset, rawData, static_cast<size_t>(outSize));
        AAsset_close(asset);

        return rawData;
    }
}