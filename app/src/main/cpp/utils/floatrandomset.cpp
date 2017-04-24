//
// Created by fjruiz.
//

#include "utils/floatrandomset.h"


namespace utils
{
    FloatRandomSet::FloatRandomSet(float min, float max)
    :_set(min, max), _source(std::random_device()())
    {
    }

    FloatRandomSet::FloatRandomSet(float min, float max, unsigned int seed)
    : _set(min, max), _source(seed)
    {
    }

    FloatRandomSet::~FloatRandomSet()
    {
    }

    float FloatRandomSet::GetNext()
    {
        return _set(_source);
    }
}