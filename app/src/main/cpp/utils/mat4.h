//
// Created by fjruiz.
//

#ifndef MAT4_H
#define MAT4_H

#include "utils/vec4.h"

namespace utils
{
    class Mat4
    {
    public:
        Mat4();
        Mat4(const Mat4& o);
        Mat4(const float[16]);
        Mat4& operator=(const Mat4& o);
        void LoadIdentity();
        void Transpose();

        Mat4& operator+=(const Mat4&);
        Mat4& operator-=(const Mat4&);
        Mat4& operator*=(const Mat4&);
        Mat4& operator*=(float);
        Mat4& operator/=(float);
        const Mat4 operator+(const Mat4&) const;
        const Mat4 operator-(const Mat4&) const;
        const Mat4 operator*(const Mat4&) const;
        const Mat4 operator*(float) const;
        const Mat4 operator/(float) const;

        const Vec3 operator*(const Vec3 & o) const;
        const Vec4 operator*(const Vec4 & o) const;
        const Mat4 Transposed() const;
        const Mat4 Inverse() const;
        static const Mat4 Identity();
        Mat4& AddEq(const Mat4& o);
        Mat4& SubEq(const Mat4& o);
        Mat4& MultEq(const Mat4& o);
        Mat4& MultEq(const float o);
        Mat4& DivEq(const float o);
        const Mat4 Add(const Mat4& o) const;
        const Mat4 Sub(const Mat4& o) const;
        const Mat4 Mult(const Mat4& o) const;
        const Mat4 Mult(const float o) const;
        const Mat4 Div(const float o) const;
        const Vec3 Mult(const Vec3& o) const;
        const Vec4 Mult(const Vec4& o) const;
        const float Det() const;

        void Translate(float x, float y, float z);
        void Scale(float sx, float sy, float sz);

        void CalculateOrtho(float left, float right, float bottom, float top, float near, float far);
    private:
        float _content[16];
    };
}
#endif // MAT4_H