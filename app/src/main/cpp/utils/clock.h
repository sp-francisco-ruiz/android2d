//
// Created by fjruiz on 15/04/2017.
//

#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>
namespace utils
{
    class Clock
    {
    public:
        Clock();

        ~Clock();

        void Reset();

        float Seconds();

        unsigned int Millis();

        unsigned int Micros();

    private:
        Clock(const Clock &) = delete;

        Clock &operator=(const Clock &) = delete;

        std::chrono::time_point<std::chrono::system_clock> _start;
    };
}
#endif // CLOCK_H
