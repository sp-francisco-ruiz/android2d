//
// Created by fjruiz.
//

#ifndef VEC4_H
#define VEC4_H

#include "utils/vec3.h"

namespace utils
{
    class Vec4
    {

    public:

        Vec4();
        Vec4(const Vec4& o);
        Vec4(const Vec3& o, float u4);
        Vec4(float u1, float u2, float u3, float u4);
        Vec4& operator=(const Vec4& o);

        const float operator[](unsigned short int i) const;
        float& operator[](unsigned short int i);
        float x() const;
        float y() const;
        float z() const;
        float w() const;
        const Vec3 xyz() const;

        const Vec4 operator-() const;
        Vec4& operator+=(const Vec4& o);
        Vec4& operator-=(const Vec4& o);
        Vec4& operator*=(float o);
        Vec4& operator/=(float o);
        const Vec4 operator+(const Vec4& o) const;
        const Vec4 operator-(const Vec4& o) const;
        const Vec4 operator*(float o) const;
        const Vec4 operator/(float o) const;

        float operator*(const Vec4& o) const;
        float Length() const;
        float LengthSq() const;
        const Vec4 Normalized() const;

        Vec4& AddEq(const Vec4& o);
        Vec4& SubEq(const Vec4& o);
        Vec4& MultEq(const float o);
        Vec4& DivEq(const float o);
        const Vec4 Add(const Vec4& o) const;
        const Vec4 Sub(const Vec4& o) const;
        const Vec4 Mult(const float o) const;
        const Vec4 Div(const float o) const;
        float Dot(const Vec4& o) const;

    private:
        float _content[4];
    };
}
#endif // VEC4_H