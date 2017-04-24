//
// Created by fjruiz.
//

#include "clock.h"
namespace utils
{
    Clock::Clock()
    {
        Reset();
    }

    Clock::~Clock()
    {
    }

    void Clock::Reset()
    {
        _start = std::chrono::system_clock::now();
    }

    unsigned int Clock::Millis()
    {
        return static_cast<unsigned int>(Seconds() * 1000.0f);
    }

    unsigned int Clock::Micros()
    {
        return static_cast<unsigned int>(Seconds() * 1000000.0f);
    }

    float Clock::Seconds()
    {
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsed_seconds = end - _start;
        return elapsed_seconds.count();
    }
}