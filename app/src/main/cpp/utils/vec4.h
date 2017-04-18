//
// Created by fjruiz on 14/04/2017.
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
        Vec4(const Vec4&);
        Vec4(const Vec3& o, float u4);
        Vec4(float u1, float u2, float u3, float u4);
        Vec4& operator=(const Vec4&);

        const float operator[](unsigned short int) const;
        float& operator[](unsigned short int);
        float x() const;
        float y() const;
        float z() const;
        float w() const;
        const Vec3 xyz() const;

        const Vec4 operator-() const;
        Vec4& operator+=(const Vec4&);
        Vec4& operator-=(const Vec4&);
        Vec4& operator*=(float);
        Vec4& operator/=(float);
        const Vec4 operator+(const Vec4&) const;
        const Vec4 operator-(const Vec4&) const;
        const Vec4 operator*(float) const;
        const Vec4 operator/(float) const;

        float operator*(const Vec4&) const;
        float Length() const;
        float LengthSq() const;
        const Vec4 Normalized() const;

        Vec4& AddEq(const Vec4&);
        Vec4& SubEq(const Vec4&);
        Vec4& MultEq(const float);
        Vec4& DivEq(const float);
        const Vec4 Add(const Vec4&) const;
        const Vec4 Sub(const Vec4&) const;
        const Vec4 Mult(const float) const;
        const Vec4 Div(const float) const;
        float Dot(const Vec4&) const;

    private:
        float _content[4];
    };
}
#endif // VEC4_H