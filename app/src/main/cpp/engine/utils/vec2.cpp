//
//  vec2.cpp
//
//  Created by Francisco Ruiz.
//
//
#include <cmath>
#include <cassert>

#include "engine/utils/vec2.h"

namespace engine
{
    namespace utils
    {

        Vec2::Vec2(void)
        {
            content_[0] = 0;
            content_[1] = 0;
        }

        Vec2::Vec2(const Vec2& o)
        {
            content_[0] = o.content_[0];
            content_[1] = o.content_[1];
        }

        Vec2::Vec2(float u1, float u2)
        {
            content_[0] = u1;
            content_[1] = u2;
        }

        Vec2& Vec2::operator=(const Vec2& o)
        {
            content_[0] = o.content_[0];
            content_[1] = o.content_[1];
            return *this;
        }

        const float Vec2::operator[](unsigned short int index) const
        {
            assert("const float Vec2::operator[]" && index >= 0 && index <= 1);
            return content_[index];
        }

        float& Vec2::operator[](unsigned short int index)
        {
            assert("float& operator[]" && index >= 0 && index <= 1);
            return content_[index];
        }

        float Vec2::x() const { return content_[0]; }
        float Vec2::y() const { return content_[1]; }
        float Vec2::width() const { return content_[0]; }
        float Vec2::height() const { return content_[1]; }

        const Vec2 Vec2::operator-() const
        {
            Vec2 res(-content_[0], -content_[1]);
            return res;
        }

        float Vec2::length() const
        {
            return sqrtf(content_[0] * content_[0] + content_[1] * content_[1]);
        }

        float Vec2::lengthSqr() const
        {
            return content_[0] * content_[0] + content_[1] * content_[1];
        }

        const Vec2 Vec2::normalized() const
        {
            return this->Div(length());
        }

        const Vec2 Vec2::tangent() const
        {
            Vec2 res(-content_[1], content_[0]);
            return res;
        }

        Vec2& Vec2::AddEq(const Vec2& o)
        {
            content_[0] += o.content_[0];
            content_[1] += o.content_[1];
            return *this;
        }

        Vec2& Vec2::SubEq(const Vec2& o)
        {
            content_[0] -= o.content_[0];
            content_[1] -= o.content_[1];
            return *this;
        }

        Vec2& Vec2::MultEq(const float o)
        {
            content_[0] *= o;
            content_[1] *= o;
            return *this;
        }

        Vec2& Vec2::DivEq(const float o)
        {
            assert("Vec2::DivEq" && o != 0);
            content_[0] /= o;
            content_[1] /= o;
            return *this;
        }

        const Vec2 Vec2::Add(const Vec2& o) const
        {
            Vec2 res(o.content_[0] + content_[0], o.content_[1] + content_[1]);
            return res;
        }

        const Vec2 Vec2::Sub(const Vec2& o) const
        {
            Vec2 res(content_[0] - o.content_[0], content_[1] - o.content_[1]);
            return res;
        }

        const Vec2 Vec2::Mult(const float o) const
        {
            Vec2 res(o*content_[0], o*content_[1]);
            return res;
        }

        const Vec2 Vec2::Div(const float o) const
        {
            assert("Vec2::Div" && o != 0);
            Vec2 res(content_[0] / o, content_[1] / o);
            return res;
        }

        float Vec2::Dot(const Vec2& o) const
        {
            return content_[0] * o.content_[0] + content_[1] * o.content_[1];
        }

        const bool Vec2::operator==(Vec2 &o)
        {
            return content_[1] == o.content_[1] && content_[0] == o.content_[0];
        }

        const bool Vec2::operator==(const Vec2 &o)
        {
            return content_[1] == o.content_[1] && content_[0] == o.content_[0];
        }

        const bool Vec2::operator!=(Vec2 &o)
        {
            return content_[1] != o.content_[1] || content_[0] != o.content_[0];
        }

        const bool Vec2::operator!=(const Vec2 &o)
        {
            return content_[1] != o.content_[1] || content_[0] != o.content_[0];
        }

        Vec2& Vec2::operator+=(const Vec2& o) { return AddEq(o); }
        Vec2& Vec2::operator-=(const Vec2& o) { return SubEq(o); }
        Vec2& Vec2::operator*=(const float o) { return MultEq(o); }
        Vec2& Vec2::operator/=(const float o) { return DivEq(o); }

        const Vec2 Vec2::operator+(const Vec2& o) const { return Add(o); }
        const Vec2 Vec2::operator-(const Vec2& o) const { return Sub(o); }
        const Vec2 Vec2::operator*(const float o) const { return Mult(o); }
        const Vec2 Vec2::operator/(const float o) const { return Div(o); }

        float Vec2::operator*(const Vec2& o) const { return Dot(o); }
    }
}