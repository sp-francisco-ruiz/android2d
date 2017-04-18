//
// Created by fjruiz on 14/04/2017.
//
#include <cassert>

#include "utils/mat4.h"

#define DET2(a,b,c,d) ( a*d - b*c )
#define DET3(a,b,c,d,e,f,g,h,i) ( a*DET2(e,f,h,i) - b*DET2(d,f,g,i) + c*DET2(d,e,g,h) )
#define DET4(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) ( a*DET3(f,g,h,j,k,l,n,o,p) - b*DET3(e,g,h,i,k,l,m,o,p) + c*DET3(e,f,h,i,j,l,m,n,p) - d*DET3(e,f,g,i,j,k,m,n,o) )

namespace utils
{
    Mat4::Mat4()
    {
        LoadIdentity();
    }

    Mat4::Mat4(const Mat4& o)
    {
        _content[0]  = o._content[0];
        _content[1]  = o._content[1];
        _content[2]  = o._content[2];
        _content[3]  = o._content[3];
        _content[4]  = o._content[4];
        _content[5]  = o._content[5];
        _content[6]  = o._content[6];
        _content[7]  = o._content[7];
        _content[8]  = o._content[8];
        _content[9]  = o._content[9];
        _content[10] = o._content[10];
        _content[11] = o._content[11];
        _content[12] = o._content[12];
        _content[13] = o._content[13];
        _content[14] = o._content[14];
        _content[15] = o._content[15];
    }

    Mat4::Mat4(const float o[16])
    {
        _content[0]  = o[0];
        _content[1]  = o[1];
        _content[2]  = o[2];
        _content[3]  = o[3];
        _content[4]  = o[4];
        _content[5]  = o[5];
        _content[6]  = o[6];
        _content[7]  = o[7];
        _content[8]  = o[8];
        _content[9]  = o[9];
        _content[10] = o[10];
        _content[11] = o[11];
        _content[12] = o[12];
        _content[13] = o[13];
        _content[14] = o[14];
        _content[15] = o[15];
    }

    Mat4& Mat4::operator=(const Mat4& o)
    {
        _content[0]  = o._content[0];
        _content[1]  = o._content[1];
        _content[2]  = o._content[2];
        _content[3]  = o._content[3];
        _content[4]  = o._content[4];
        _content[5]  = o._content[5];
        _content[6]  = o._content[6];
        _content[7]  = o._content[7];
        _content[8]  = o._content[8];
        _content[9]  = o._content[9];
        _content[10] = o._content[10];
        _content[11] = o._content[11];
        _content[12] = o._content[12];
        _content[13] = o._content[13];
        _content[14] = o._content[14];
        _content[15] = o._content[15];
        return *this;
    }

    void Mat4::LoadIdentity()
    {
        _content[0]  = 1.0f; _content[1]  = 0.0f; _content[2]  = 0.0f; _content[3]  = 0.0f;
        _content[4]  = 0.0f; _content[5]  = 1.0f; _content[6]  = 0.0f; _content[7]  = 0.0f;
        _content[8]  = 0.0f; _content[9]  = 0.0f; _content[10] = 1.0f; _content[11] = 0.0f;
        _content[12] = 0.0f; _content[13] = 0.0f; _content[14] = 0.0f; _content[15] = 1.0f;
    }

    void Mat4::Transpose()
    {
        Mat4(Transposed());
    }

    const Mat4 Mat4::Identity()
    {
        float content[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
        Mat4 res(content);
        return res;
    }

    const Mat4 Mat4::Transposed() const
    {
        float content[16] =
        {
            _content[0], _content[4], _content[8], _content[12],
            _content[1], _content[5], _content[9], _content[13],
            _content[2], _content[6], _content[10], _content[14],
            _content[3], _content[7], _content[11], _content[15]
        };

        Mat4 res(content);
        return res;
    }

    Mat4& Mat4::MultEq(const Mat4& o)
    {
        *this = Mult(o);
        return *this;
    }

    const Mat4 Mat4::Mult(const Mat4& o) const
    {
        float content[16]=
        {
            _content[0]*o._content[0] +_content[4]*o._content[1] +_content[8] *o._content[2] +_content[12]*o._content[3],
            _content[1]*o._content[0] +_content[5]*o._content[1] +_content[9] *o._content[2] +_content[13]*o._content[3],
            _content[2]*o._content[0] +_content[6]*o._content[1] +_content[10]*o._content[2] +_content[14]*o._content[3],
            _content[3]*o._content[0] +_content[7]*o._content[1] +_content[11]*o._content[2] +_content[15]*o._content[3],
            _content[0]*o._content[4] +_content[4]*o._content[5] +_content[8] *o._content[6] +_content[12]*o._content[7],
            _content[1]*o._content[4] +_content[5]*o._content[5] +_content[9] *o._content[6] +_content[13]*o._content[7],
            _content[2]*o._content[4] +_content[6]*o._content[5] +_content[10]*o._content[6] +_content[14]*o._content[7],
            _content[3]*o._content[4] +_content[7]*o._content[5] +_content[11]*o._content[6] +_content[15]*o._content[7],
            _content[0]*o._content[8] +_content[4]*o._content[9] +_content[8] *o._content[10]+_content[12]*o._content[11],
            _content[1]*o._content[8] +_content[5]*o._content[9] +_content[9] *o._content[10]+_content[13]*o._content[11],
            _content[2]*o._content[8] +_content[6]*o._content[9] +_content[10]*o._content[10]+_content[14]*o._content[11],
            _content[3]*o._content[8] +_content[7]*o._content[9] +_content[11]*o._content[10]+_content[15]*o._content[11],
            _content[0]*o._content[12]+_content[4]*o._content[13]+_content[8] *o._content[14]+_content[12]*o._content[15],
            _content[1]*o._content[12]+_content[5]*o._content[13]+_content[9] *o._content[14]+_content[13]*o._content[15],
            _content[2]*o._content[12]+_content[6]*o._content[13]+_content[10]*o._content[14]+_content[14]*o._content[15],
            _content[3]*o._content[12]+_content[7]*o._content[13]+_content[11]*o._content[14]+_content[15]*o._content[15]
        };
        Mat4 res(content);
        return res;
    }

    const Vec4 Mat4::Mult(const Vec4& o) const
    {
        Vec4 res(o.x()*_content[0] +o.y()*_content[1] +o.z()*_content[2] +o.w()*_content[3],
                 o.x()*_content[4] +o.y()*_content[5] +o.z()*_content[6] +o.w()*_content[7],
                 o.x()*_content[8] +o.y()*_content[9] +o.z()*_content[10]+o.w()*_content[11],
                 o.x()*_content[12]+o.y()*_content[13]+o.z()*_content[14]+o.w()*_content[15]);
        return res;
    }


    Mat4& Mat4::AddEq(const Mat4& o)
    {
        _content[0] += o._content[0];
        _content[1] += o._content[1];
        _content[2] += o._content[2];
        _content[3] += o._content[3];
        _content[4] += o._content[4];
        _content[5] += o._content[5];
        _content[6] += o._content[6];
        _content[7] += o._content[7];
        _content[8] += o._content[8];
        _content[9] += o._content[9];
        _content[10] += o._content[10];
        _content[11] += o._content[11];
        _content[12] += o._content[12];
        _content[13] += o._content[13];
        _content[14] += o._content[14];
        _content[15] += o._content[15];
        return *this;
    }

    Mat4& Mat4::SubEq(const Mat4& o)
    {
        _content[0]  -= o._content[0];
        _content[1]  -= o._content[1];
        _content[2]  -= o._content[2];
        _content[3]  -= o._content[3];
        _content[4]  -= o._content[4];
        _content[5]  -= o._content[5];
        _content[6]  -= o._content[6];
        _content[7]  -= o._content[7];
        _content[8]  -= o._content[8];
        _content[9]  -= o._content[9];
        _content[10] -= o._content[10];
        _content[11] -= o._content[11];
        _content[12] -= o._content[12];
        _content[13] -= o._content[13];
        _content[14] -= o._content[14];
        _content[15] -= o._content[15];
        return *this;
    }

    Mat4& Mat4::MultEq(const float o)
    {
        _content[0]  *= o;
        _content[1]  *= o;
        _content[2]  *= o;
        _content[3]  *= o;
        _content[4]  *= o;
        _content[5]  *= o;
        _content[6]  *= o;
        _content[7]  *= o;
        _content[8]  *= o;
        _content[9]  *= o;
        _content[10] *= o;
        _content[11] *= o;
        _content[12] *= o;
        _content[13] *= o;
        _content[14] *= o;
        _content[15] *= o;
        return *this;
    }

    Mat4& Mat4::DivEq(const float o)
    {
        assert("Mat4::DivEq" && o!=0);
        _content[0]  /= o;
        _content[1]  /= o;
        _content[2]  /= o;
        _content[3]  /= o;
        _content[4]  /= o;
        _content[5]  /= o;
        _content[6]  /= o;
        _content[7]  /= o;
        _content[8]  /= o;
        _content[9]  /= o;
        _content[10] /= o;
        _content[11] /= o;
        _content[12] /= o;
        _content[13] /= o;
        _content[14] /= o;
        _content[15] /= o;
        return *this;
    }

    const Mat4 Mat4::Add(const Mat4& o) const
    {
        float content[16]=
        {
            _content[0]  + o._content[0],
            _content[1]  + o._content[1],
            _content[2]  + o._content[2],
            _content[3]  + o._content[3],
            _content[4]  + o._content[4],
            _content[5]  + o._content[5],
            _content[6]  + o._content[6],
            _content[7]  + o._content[7],
            _content[8]  + o._content[8],
            _content[9]  + o._content[9],
            _content[10] + o._content[10],
            _content[11] + o._content[11],
            _content[12] + o._content[12],
            _content[13] + o._content[13],
            _content[14] + o._content[14],
            _content[15] + o._content[15]
        };
        Mat4 res(content);
        return res;
    }

    const Mat4 Mat4::Sub(const Mat4& o) const
    {
        float content[16]=
        {
            _content[0]  - o._content[0],
            _content[1]  - o._content[1],
            _content[2]  - o._content[2],
            _content[3]  - o._content[3],
            _content[4]  - o._content[4],
            _content[5]  - o._content[5],
            _content[6]  - o._content[6],
            _content[7]  - o._content[7],
            _content[8]  - o._content[8],
            _content[9]  - o._content[9],
            _content[10] - o._content[10],
            _content[11] - o._content[11],
            _content[12] - o._content[12],
            _content[13] - o._content[13],
            _content[14] - o._content[14],
            _content[15] - o._content[15]
        };
        Mat4 res(content);
        return res;
    }

    const Mat4 Mat4::Mult(const float o) const
    {
        float content[16]=
        {
            _content[0]  * o,
            _content[1]  * o,
            _content[2]  * o,
            _content[3]  * o,
            _content[4]  * o,
            _content[5]  * o,
            _content[6]  * o,
            _content[7]  * o,
            _content[8]  * o,
            _content[9]  * o,
            _content[10] * o,
            _content[11] * o,
            _content[12] * o,
            _content[13] * o,
            _content[14] * o,
            _content[15] * o
        };
        Mat4 res(content);
        return res;
    }
    const Mat4 Mat4::Div(const float o) const
    {
        assert("Mat4::Div" && o!=0);
        float content[16]=
        {
            _content[0]  / o,
            _content[1]  / o,
            _content[2]  / o,
            _content[3]  / o,
            _content[4]  / o,
            _content[5]  / o,
            _content[6]  / o,
            _content[7]  / o,
            _content[8]  / o,
            _content[9]  / o,
            _content[10] / o,
            _content[11] / o,
            _content[12] / o,
            _content[13] / o,
            _content[14] / o,
            _content[15] / o
        };
        Mat4 res(content);
        return res;
    }

    Mat4& Mat4::operator+=(const Mat4& o)
    {
        return AddEq(o);
    }

    Mat4& Mat4::operator-=(const Mat4& o)
    {
        return SubEq(o);
    }

    Mat4& Mat4::operator*=(const Mat4& o)
    {
        return MultEq(o);
    }

    Mat4& Mat4::operator*=(float o)
    {
        return MultEq(o);
    }

    Mat4& Mat4::operator/=(float o)
    {
        return DivEq(o);
    }

    const Mat4 Mat4::operator+(const Mat4& o) const
    {
        return Add(o);
    }

    const Mat4 Mat4::operator-(const Mat4& o) const
    {
        return Sub(o);
    }

    const Mat4 Mat4::operator*(const Mat4& o) const
    {
        return Mult(o);
    }

    const Mat4 Mat4::operator*(float o) const
    {
        return Mult(o);
    }

    const Mat4 Mat4::operator/(float o) const
    {
        return Div(o);
    }

    const Vec4 Mat4::operator*(const Vec4& o) const
    {
        return Mult(o);
    }

    const Vec3 Mat4::operator*(const Vec3& o) const
    {
        return Mult(o);
    }

    const Vec3 Mat4::Mult(const Vec3& o) const
    {
        Vec3 res(o.x()*_content[0]+o.y()*_content[1]+o.z()*_content[2],
                 o.x()*_content[4]+o.y()*_content[5]+o.z()*_content[6],
                 o.x()*_content[8]+o.y()*_content[9]+o.z()*_content[10]);
        return res;
    }

    const float Mat4::Det() const
    {
        return DET4(_content[0],  _content[1],  _content[2],  _content[3],
                    _content[4],  _content[5],  _content[6],  _content[7],
                    _content[8],  _content[9],  _content[10], _content[11],
                    _content[12], _content[13], _content[14], _content[15]);
    }

    const Mat4 Mat4::Inverse() const
    {

        float content[16];

        const float min_0 = DET3(_content[5],_content[6],_content[7],
                                 _content[9],_content[10],_content[11],
                                 _content[13],_content[14],_content[15]);

        const float min_4 = DET3(_content[1],_content[2],_content[3],
                                 _content[9],_content[10],_content[11],
                                 _content[13],_content[14],_content[15]);

        const float min_8 = DET3(_content[1],_content[2],_content[3],
                                 _content[5],_content[6],_content[7],
                                 _content[13],_content[14],_content[15]);

        const float min_12 = DET3(_content[1],_content[2],_content[3],
                                  _content[5],_content[6],_content[7],
                                  _content[9],_content[10],_content[11]);

        const float det_m = _content[0]*min_0 - _content[4]*min_4 + _content[8]*min_8 - _content[12]*min_12;

        if(det_m!=0)
        {

            content[0] =  min_0 * (1.0f/det_m);

            content[1] = -DET3(_content[4],_content[6],_content[7],
                               _content[8],_content[10],_content[11],
                               _content[12],_content[14],_content[15]) * (1.0f/det_m);

            content[2] = DET3(_content[4],_content[5],_content[7],
                              _content[8],_content[9],_content[11],
                              _content[12],_content[13],_content[15]) * (1.0f/det_m);

            content[3] = -DET3(_content[4],_content[5],_content[6],
                               _content[8],_content[9],_content[10],
                               _content[12],_content[13],_content[14]) * (1.0f/det_m);

            content[4] = -min_4 * (1.0f/det_m);

            content[5] = DET3(_content[0],_content[2],_content[3],
                              _content[8],_content[10],_content[11],
                              _content[12],_content[14],_content[15]) * (1.0f/det_m);

            content[6] = -DET3(_content[0],_content[1],_content[3],
                               _content[8],_content[9],_content[11],
                               _content[12],_content[13],_content[15]) * (1.0f/det_m);

            content[7] = DET3(_content[0],_content[1],_content[2],
                              _content[8],_content[9],_content[10],
                              _content[12],_content[13],_content[14]) * (1.0f/det_m);

            content[8] =  min_8 * (1.0f/det_m);

            content[9] = -DET3(_content[0],_content[2],_content[3],
                               _content[4],_content[6],_content[7],
                               _content[12],_content[14],_content[15]) * (1.0f/det_m);

            content[10] = DET3(_content[0],_content[1],_content[3],
                               _content[4],_content[5],_content[7],
                               _content[12],_content[13],_content[15]) * (1.0f/det_m);

            content[11] = -DET3(_content[0],_content[1],_content[2],
                                _content[4],_content[5],_content[6],
                                _content[12],_content[13],_content[14]) * (1.0f/det_m);

            content[12] = -min_12 * (1.0f/det_m);

            content[13] = DET3(_content[0],_content[2],_content[3],
                               _content[4],_content[6],_content[7],
                               _content[8],_content[10],_content[11]) * (1.0f/det_m);

            content[14] = -DET3(_content[0],_content[1],_content[3],
                                _content[4],_content[5],_content[7],
                                _content[8],_content[9],_content[11]) * (1.0f/det_m);

            content[15] = DET3(_content[0],_content[1],_content[2],
                               _content[4],_content[5],_content[6],
                               _content[8],_content[9],_content[10]) * (1.0f/det_m);

        }

        Mat4 res(content);
        return res.Transposed();
    }

    void Mat4::Translate(float x, float y, float z)
    {
        _content[12] = x;
        _content[13] = y;
        _content[14] = z;
    }

    void Mat4::Scale(float sx, float sy, float sz)
    {
        _content[0] = sx;
        _content[5] = sy;
        _content[10] = sz;
    }

    void Mat4::CalculateOrtho(float left, float right, float bottom, float top, float near, float far)
    {
        _content[0] = 2.0f / (right - left);
        _content[1] = 0.0f;
        _content[2] = 0.0f;
        _content[3] = 0.0f;

        _content[4] = 0.0f;
        _content[5] = 2.0f / (top - bottom);
        _content[6] = 0.0f;
        _content[7] = 0.0f;

        _content[8] = 0.0f;
        _content[9] = 0.0f;
        _content[10] = 2.0f / (far - near);
        _content[11] = 0.0f;

        _content[12] = -(right + left) / (right - left);
        _content[13] = -(top + bottom) / (top - bottom);
        _content[14] = -(far + near) / (far - near);
        _content[15] = 1.0f;
    }
}