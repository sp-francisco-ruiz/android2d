//
//  IntRandomSet.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef INTRANDOMSET_H
#define INTRANDOMSET_H

#include <random>

namespace engine
{
    namespace utils
    {
        class IntRandomSet
        {
        public:
            IntRandomSet(int min, int max);
            IntRandomSet(int min, int max, unsigned int seed);
            ~IntRandomSet();

            int GetNext();

        private:
            IntRandomSet(const IntRandomSet&) = delete;
            IntRandomSet& operator = (const IntRandomSet&) = delete;

            std::uniform_int_distribution<int> _set;
            std::mt19937 _source;
        };
    }
}
#endif // INTRANDOMSET_H
