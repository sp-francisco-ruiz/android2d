//
//  vec2.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef VEC2_H
#define VEC2_H

namespace engine
{
    namespace utils
    {
        class Vec2
        {

        private:
            float content_[2];

        public:

            Vec2();
            Vec2(const Vec2& o);
            Vec2(float u1, float u2);
            Vec2& operator=(const Vec2& o);

            const float operator[](unsigned short int index) const;

            float& operator[](unsigned short int index);

            float x() const;
            float y() const;
            float width() const;
            float height() const;

            const Vec2 operator-() const;

            Vec2& operator+=(const Vec2& o);
            Vec2& operator-=(const Vec2& o);
            Vec2& operator*=(const float o);
            Vec2& operator/=(const float o);

            const Vec2 operator+(const Vec2& o) const;
            const Vec2 operator-(const Vec2& o) const;
            const Vec2 operator*(const float o) const;
            const Vec2 operator/(const float o) const;

            float operator*(const Vec2& o) const;

            float length() const;
            float lengthSqr() const;
            const Vec2 normalized() const;
            const Vec2 tangent() const;

            Vec2& AddEq(const Vec2& o);
            Vec2& SubEq(const Vec2& o);
            Vec2& MultEq(const float o);
            Vec2& DivEq(const float o);
            const Vec2 Add(const Vec2& o) const;
            const Vec2 Sub(const Vec2& o) const;
            const Vec2 Mult(const float o) const;
            const Vec2 Div(const float o) const;
            float Dot(const Vec2& o) const;

            const bool operator==(Vec2 &o);
            const bool operator!=(Vec2 &o);
            const bool operator==(const Vec2 &o);
            const bool operator!=(const Vec2 &o);
        };
    }
}
#endif // VEC2_H
