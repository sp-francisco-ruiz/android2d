//
//  FileUtils.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

namespace engine
{
    namespace utils
    {
        class FileUtils
        {
        public:
            static const std::string& ReadFromFile(const char* path);
        };

    }
}

#endif // FILEUTILS_H
