//
// Created by fjruiz.
//

#ifndef CLOCK_H
#define CLOCK_H

namespace utils
{
    class Clock
    {
    public:
        Clock();

        ~Clock();

        void Reset();

        float Seconds();

        long Millis();

        long Micros();

    private:
        Clock(const Clock &) = delete;

        Clock &operator=(const Clock &) = delete;

        long _start;
    };
}
#endif // CLOCK_H
