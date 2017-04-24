//
// Created by fjruiz.
//

#ifndef FLOATRANDOMSET_H
#define FLOATRANDOMSET_H

#include <random>

namespace utils
{
    class FloatRandomSet
    {
    public:
        FloatRandomSet(float min, float max);
        FloatRandomSet(float min, float max, unsigned int seed);
        ~FloatRandomSet();

        float GetNext();

    private:
        FloatRandomSet(const FloatRandomSet&) = delete;
        FloatRandomSet& operator = (const FloatRandomSet&) = delete;

        std::uniform_real_distribution<float> _set;
        std::mt19937 _source;
    };
}
#endif // FLOATRANDOMSET_H
