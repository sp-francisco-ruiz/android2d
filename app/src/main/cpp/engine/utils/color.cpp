//
//  Color.cpp
//
//  Created by Francisco Ruiz.
//
//

#include <cmath>
#include <cassert>

#include "engine/utils/color.h"

namespace engine
{
    namespace utils
    {
        Color::Color(void)
        {
            content_[0] = 1.0f;
            content_[1] = 1.0f;
            content_[2] = 1.0f;
            content_[3] = 1.0f;
        }

        Color::Color(const Color& o)
        {
            content_[0] = o.content_[0];
            content_[1] = o.content_[1];
            content_[2] = o.content_[2];
            content_[3] = o.content_[3];
        }

        Color::Color(float r, float g, float b, float a)
        {
            setR(r);
            setG(g);
            setB(b);
            setA(a);
        }

        Color& Color::operator=(const Color& o)
        {
            content_[0] = o.content_[0];
            content_[1] = o.content_[1];
            content_[2] = o.content_[2];
            content_[3] = o.content_[3];
            return *this;
        }

        float Color::r() const { return content_[0]; }
        float Color::g() const { return content_[1]; }
        float Color::b() const { return content_[2]; }
        float Color::a() const { return content_[3]; }

        void Color::setR(float value)
        {
            content_[0] = fmaxf(fminf(value, 1.0f), 0.0f);
        }

        void Color::setG(float value)
        {
            content_[1] = fmaxf(fminf(value, 1.0f), 0.0f);
        }

        void Color::setB(float value)
        {
            content_[2] = fmaxf(fminf(value, 1.0f), 0.0f);
        }

        void Color::setA(float value)
        {
            content_[3] = fmaxf(fminf(value, 1.0f), 0.0f);
        }

        void Color::set(float r, float g, float b)
        {
            setR(r);
            setG(g);
            setB(b);
        }

        void Color::set(float r, float g, float b, float a)
        {
            set(r, g, b);
            setA(a);
        }

        Color& Color::AddEq(const Color& o)
        {
            setR(content_[0] + o.content_[0]);
            setG(content_[1] + o.content_[1]);
            setB(content_[2] + o.content_[2]);
            setA(content_[3] + o.content_[3]);
            return *this;
        }

        Color& Color::SubEq(const Color& o)
        {
            setR(content_[0] - o.content_[0]);
            setG(content_[1] - o.content_[1]);
            setB(content_[2] - o.content_[2]);
            setA(content_[3] - o.content_[3]);
            return *this;
        }

        Color& Color::MultEq(const float o)
        {
            setR(content_[0] * o);
            setG(content_[1] * o);
            setB(content_[2] * o);
            setA(content_[3] * o);
            return *this;
        }

        Color& Color::MultEq(const Color& o)
        {
            setR(content_[0] * o.content_[0]);
            setG(content_[1] * o.content_[1]);
            setB(content_[2] * o.content_[2]);
            setA(content_[3] * o.content_[3]);
            return *this;
        }

        Color& Color::DivEq(const float o)
        {
            assert("Vec2::DivEq" && o != 0);
            setR(content_[0] / o);
            setG(content_[1] / o);
            setB(content_[2] / o);
            setA(content_[3] / o);
            return *this;
        }

        const Color Color::Add(const Color& o) const
        {
            Color res(o.content_[0] + content_[0], o.content_[1] + content_[1], o.content_[2] + content_[2], o.content_[3] + content_[3]);
            return res;
        }

        const Color Color::Sub(const Color& o) const
        {
            Color res(content_[0] - o.content_[0], content_[1] - o.content_[1], content_[2] - o.content_[2], content_[3] - o.content_[3]);
            return res;
        }

        const Color Color::Mult(const float o) const
        {
            Color res(o*content_[0], o*content_[1], o*content_[2], o*content_[3]);
            return res;
        }

        const Color Color::Mult(const Color &o) const
        {
            Color res(o.content_[0] * content_[0], o.content_[1] * content_[1], o.content_[2] * content_[2], o.content_[3] * content_[3]);
            return res;
        }

        const Color Color::Div(const float o) const
        {
            assert("Vec2::Div" && o != 0);
            Color res(content_[0] / o, content_[1] / o, content_[2] / o, content_[3] / o);
            return res;
        }

        Color& Color::operator+=(const Color& o) { return AddEq(o); }
        Color& Color::operator-=(const Color& o) { return SubEq(o); }
        Color& Color::operator*=(const Color& o) { return MultEq(o); }
        Color& Color::operator*=(const float o) { return MultEq(o); }
        Color& Color::operator/=(const float o) { return DivEq(o); }

        const Color Color::operator+(const Color& o) const { return Add(o); }
        const Color Color::operator-(const Color& o) const { return Sub(o); }
        const Color Color::operator*(const Color& o) const { return Mult(o); }
        const Color Color::operator*(const float o) const { return Mult(o); }
        const Color Color::operator/(const float o) const { return Div(o); }
    }
}