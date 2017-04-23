//
//  FileUtils.cpp
//
//  Created by Francisco Ruiz.
//
//
#include <string>
#include <stdio.h>

#include "engine/utils/fileutils.h"

namespace engine
{
    namespace utils
    {
        namespace
        {
            std::string _lastReadName;
            std::string _lastReadContent;
        }

        const std::string& FileUtils::ReadFromFile(const char* path)
        {
            /*
            if (_lastReadName == path && _lastReadContent.length() > 0)
            {
                return _lastReadContent;
            }

            _lastReadContent.clear();

            size_t blocks;
            char* buf;
            SDL_RWops *rw = SDL_RWFromFile(path, "rb");
            if (rw == nullptr)
            {
                printf("Couldn't open file.bin\n");
                return _lastReadContent;
            }
            long long size = rw->size(rw) + 1LL;
            buf = (char*)malloc(size);

            blocks = SDL_RWread(rw, buf, 1, size);
            SDL_RWclose(rw);
            if (blocks < 0)
            {
                printf("Couldn't read from file %s\n", path);
                return _lastReadContent;
            }
            buf[blocks] = '\0';

            _lastReadContent = std::string(buf);
            _lastReadName = path;

            free(buf);
             */
            return _lastReadContent;
        }
    }
}