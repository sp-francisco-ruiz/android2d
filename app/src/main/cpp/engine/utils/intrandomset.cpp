//
//  IntRandomSet.cpp
//
//  Created by Francisco Ruiz.
//
//

#include "engine/utils/intrandomset.h"

namespace engine
{
    namespace utils
    {
        IntRandomSet::IntRandomSet(int min, int max)
            :_set(min, max), _source(std::random_device()())
        {
        }

        IntRandomSet::IntRandomSet(int min, int max, unsigned int seed)
            : _set(min, max), _source(seed)
        {
        }

        IntRandomSet::~IntRandomSet()
        {
        }

        int IntRandomSet::GetNext()
        {
            return _set(_source);
        }
    }
}