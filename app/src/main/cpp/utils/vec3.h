//
// Created by fjruiz on 14/04/2017.
//

#ifndef VEC3_H
#define VEC3_H

namespace utils
{
    class Vec3
    {

    public:
        Vec3();
        Vec3(const Vec3& o);
        Vec3(float u1, float u2, float u3);
        Vec3& operator=(const Vec3& o);

        const float operator[](unsigned short int index) const;
        float& operator[](unsigned short int index);
        float x() const;
        float y() const;
        float z() const;

        const Vec3 operator-() const;
        Vec3& operator+=(const Vec3& o);
        Vec3& operator-=(const Vec3& o);
        Vec3& operator*=(float o);
        Vec3& operator/=(float o);
        const Vec3 operator+(const Vec3& o) const;
        const Vec3 operator-(const Vec3& o) const;
        const Vec3 operator^(const Vec3& o) const;
        const Vec3 operator*(float o) const;
        const Vec3 operator/(float o) const;
        float operator*(const Vec3& o) const;

        float length() const;
        float lengthsq() const;
        const Vec3 normalized() const;
        const Vec3 tangent(const Vec3& o) const;
        Vec3& AddEq(const Vec3& o);
        Vec3& SubEq(const Vec3& o);
        Vec3& MultEq(const float o);
        Vec3& DivEq(const float o);
        const Vec3 Add(const Vec3& o) const;
        const Vec3 Sub(const Vec3& o) const;
        const Vec3 Mult(const float o) const;
        const Vec3 Div(const float o) const;
        float Dot(const Vec3& o) const;

        static const Vec3 Cross( const Vec3& a, const Vec3& b);

    private:
        float _content[3];
    };
}
#endif // VEC3_H