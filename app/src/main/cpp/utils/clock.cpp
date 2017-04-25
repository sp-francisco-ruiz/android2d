//
// Created by fjruiz.
//

#include "clock.h"

#include <chrono>
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
        auto duration = std::chrono::system_clock::now().time_since_epoch();
        _start = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    }

    long Clock::Millis()
    {
        auto end = std::chrono::system_clock::now().time_since_epoch();
        long endTS = std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
        return endTS - _start;
    }

    long Clock::Micros()
    {
        return Millis() * 1000;
    }

    float Clock::Seconds()
    {
        return Millis() * 0.001f;
    }
}