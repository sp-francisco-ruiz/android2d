//
// Created by fjruiz on 14/04/2017.
//
#include <cassert>
#include <cmath>

#include "engine/utils/vec4.h"

namespace engine
{
    namespace utils
    {
        Vec4::Vec4()
        {
            _content[0] = 0.0f;
            _content[1] = 0.0f;
            _content[2] = 0.0f;
            _content[3] = 0.0f;
        }

        Vec4::Vec4(const Vec4& o)
        {
            _content[0] = o._content[0];
            _content[1] = o._content[1];
            _content[2] = o._content[2];
            _content[3] = o._content[3];
        }

        Vec4::Vec4(float u1, float u2, float u3, float u4)
        {
            _content[0] = u1;
            _content[1] = u2;
            _content[2] = u3;
            _content[3] = u4;
        }

        Vec4::Vec4(const Vec3& o, float u4)
        {
            _content[0] = o.x();
            _content[1] = o.y();
            _content[2] = o.z();
            _content[3] = u4;
        }

        Vec4& Vec4::operator=(const Vec4& o)
        {
            _content[0] = o._content[0];
            _content[1] = o._content[1];
            _content[2] = o._content[2];
            _content[3] = o._content[3];
            return *this;
        }

        const float Vec4::operator[](unsigned short int index) const
        {
            assert("const float Vec4::operator[]" && index > -1 && index < 4);
            return _content[index];
        }

        float& Vec4::operator[](unsigned short int index)
        {
            assert("float& Vec4::operator[]" && index > -1 && index < 4);
            return _content[index];
        }

        float Vec4::x() const{return _content[0];}
        float Vec4::y() const{return _content[1];}
        float Vec4::z() const{return _content[2];}
        float Vec4::w() const{return _content[3];}

        const Vec3 Vec4::xyz() const
        {
            return Vec3(_content[0], _content[1], _content[2]);
        }

        const Vec4 Vec4::operator-() const
        {
            Vec4 res(-_content[0], -_content[1], -_content[2], -_content[3]);
            return res;
        }

        float Vec4::Length() const
        {
            return sqrtf(_content[0] * _content[0] +
                         _content[1] * _content[1] +
                         _content[2] * _content[2] +
                         _content[3] * _content[3]);
        }

        float Vec4::LengthSq() const{
            return _content[0] * _content[0] +
                   _content[1] * _content[1] +
                   _content[2] * _content[2] +
                   _content[3] * _content[3];
        }

        const Vec4 Vec4::Normalized() const
        {
            return this->Div(Length());
        }

        Vec4& Vec4::AddEq(const Vec4& o)
        {
            _content[0]+=o._content[0];
            _content[1]+=o._content[1];
            _content[2]+=o._content[2];
            _content[3]+=o._content[3];
            return *this;
        }

        Vec4& Vec4::SubEq(const Vec4& o)
        {
            _content[0]-=o._content[0];
            _content[1]-=o._content[1];
            _content[2]-=o._content[2];
            _content[3]-=o._content[3];
            return *this;
        }

        Vec4& Vec4::MultEq(const float o)
        {
            _content[0]*=o;
            _content[1]*=o;
            _content[2]*=o;
            _content[3]*=o;
            return *this;
        }

        Vec4& Vec4::DivEq(const float o)
        {
            assert("Vec4::DivEq" && o!=0);
            _content[0]/=o;
            _content[1]/=o;
            _content[2]/=o;
            _content[3]/=o;
            return *this;
        }

        const Vec4 Vec4::Add(const Vec4& o) const
        {
            Vec4 res(o._content[0]+_content[0],
                     o._content[1]+_content[1],
                     o._content[2]+_content[2],
                     o._content[3]+_content[3]);
            return res;
        }

        const Vec4 Vec4::Sub(const Vec4& o) const
        {
            Vec4 res(_content[0]-o._content[0],
                     _content[1]-o._content[1],
                     _content[2]-o._content[2],
                     _content[3]-o._content[3]);
            return res;
        }

        const Vec4 Vec4::Mult(const float o) const
        {
            Vec4 res(o*_content[0], o*_content[1], o*_content[2], o*_content[3]);
            return res;
        }

        const Vec4 Vec4::Div(const float o) const
        {
            assert("Vec4::Div" && o!=0);
            Vec4 res(_content[0]/o, _content[1]/o, _content[2]/o, _content[3]/o);
            return res;
        }

        float Vec4::Dot(const Vec4& o) const
        {
            return _content[0] * o._content[0] +
                   _content[1] * o._content[1] +
                   _content[2] * o._content[2] +
                   _content[3] * o._content[3];
        }

        Vec4& Vec4::operator+=(const Vec4& o){return AddEq(o);}
        Vec4& Vec4::operator-=(const Vec4& o){return SubEq(o);}
        Vec4& Vec4::operator*=(const float o){return MultEq(o);}
        Vec4& Vec4::operator/=(const float o){return DivEq(o);}

        const Vec4 Vec4::operator+(const Vec4& o) const{return Add(o);}
        const Vec4 Vec4::operator-(const Vec4& o) const{return Sub(o);}
        const Vec4 Vec4::operator*(const float o) const{return Mult(o);}
        const Vec4 Vec4::operator/(const float o) const{return Div(o);}

        float Vec4::operator*(const Vec4& o) const{return Dot(o);}
    }
}