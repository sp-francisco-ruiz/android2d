//
// Created by fjruiz.
//
#include <cmath>
#include <cassert>

#include "utils/vec3.h"
namespace utils
{
    Vec3::Vec3()
    {
        _content[0]=0;
        _content[1]=0;
        _content[2]=0;
    }

    Vec3::Vec3(const Vec3& o)
    {
        _content[0] = o._content[0];
        _content[1] = o._content[1];
        _content[2] = o._content[2];
    }

    Vec3::Vec3(float u1, float u2, float u3)
    {
        _content[0] = u1;
        _content[1] = u2;
        _content[2] = u3;
    }

    Vec3& Vec3::operator=(const Vec3& o)
    {
        _content[0] = o._content[0];
        _content[1] = o._content[1];
        _content[2] = o._content[2];
        return *this;
    }

    const float Vec3::operator[](unsigned short int index) const
    {
        assert("const float Vec3::operator[]" && index > -1 && index < 3);
        return _content[index];
    }

    float& Vec3::operator[](unsigned short int index)
    {
        assert("float& Vec3::operator[]" && index > -1 && index < 3);
        return _content[index];
    }

    float Vec3::x() const{return _content[0];}
    float Vec3::y() const{return _content[1];}
    float Vec3::z() const{return _content[2];}

    const Vec3 Vec3::operator-() const
    {
        Vec3 res(-_content[0], -_content[1], -_content[2]);
        return res;
    }

    float Vec3::length() const
    {
        return sqrtf(_content[0] * _content[0] +
                     _content[1] * _content[1] +
                     _content[2] * _content[2]);
    }

    float Vec3::lengthsq() const
    {
        return _content[0] * _content[0] +
               _content[1] * _content[1] +
               _content[2] * _content[2];
    }

    const Vec3 Vec3::normalized() const{return this->Div(length());}

    const Vec3 Vec3::tangent(const Vec3& o) const
    {
        Vec3 res(_content[1] * o._content[2] - _content[2] * o._content[1],
                 _content[2] * o._content[0] - _content[0] * o._content[2],
                 _content[0] * o._content[1] - _content[1] * o._content[0]);
        return res;
    }

    Vec3& Vec3::AddEq(const Vec3& o)
    {
        _content[0]+=o._content[0];
        _content[1]+=o._content[1];
        _content[2]+=o._content[2];
        return *this;
    }

    Vec3& Vec3::SubEq(const Vec3& o)
    {
        _content[0]-=o._content[0];
        _content[1]-=o._content[1];
        _content[2]-=o._content[2];
        return *this;
    }

    Vec3& Vec3::MultEq(const float o)
    {
        _content[0]*=o;
        _content[1]*=o;
        _content[2]*=o;
        return *this;
    }

    Vec3& Vec3::DivEq(const float o)
    {
        assert("Vec3::DivEq" && o!=0);
        _content[0]/=o;
        _content[1]/=o;
        _content[2]/=o;
        return *this;
    }

    const Vec3 Vec3::Add(const Vec3& o) const
    {
        Vec3 res(o._content[0]+_content[0],
                 o._content[1]+_content[1],
                 o._content[2]+_content[2]);
        return res;
    }

    const Vec3 Vec3::Sub(const Vec3& o) const
    {
        Vec3 res(_content[0]-o._content[0],
                 _content[1]-o._content[1],
                 _content[2]-o._content[2]);
        return res;
    }

    const Vec3 Vec3::Mult(const float o) const
    {
        Vec3 res(o*_content[0], o*_content[1], o*_content[2]);
        return res;
    }

    const Vec3 Vec3::Div(const float o) const
    {
        assert("Vec3::Div" && o!=0);
        Vec3 res(_content[0]/o, _content[1]/o, _content[2]/o);
        return res;
    }

    float Vec3::Dot(const Vec3& o) const
    {
        return (_content[0] * o._content[0]) +
               (_content[1] * o._content[1]) +
               (_content[2] * o._content[2]);
    }

    const Vec3 Vec3::Cross(const Vec3& a, const Vec3& b)
    {
        Vec3 res;

        res._content[0] =  (a._content[1]*b._content[2]) - (b._content[1]*a._content[2]);
        res._content[1] = -(a._content[0]*b._content[2]) + (b._content[0]*a._content[2]);
        res._content[2] =  (a._content[0]*b._content[1]) - (a._content[1]*b._content[0]);

        return res;
    }

    Vec3& Vec3::operator+=(const Vec3& o){return AddEq(o);}
    Vec3& Vec3::operator-=(const Vec3& o){return SubEq(o);}
    Vec3& Vec3::operator*=(const float o){return MultEq(o);}
    Vec3& Vec3::operator/=(const float o){return DivEq(o);}

    const Vec3 Vec3::operator+(const Vec3& o) const{return Add(o);}
    const Vec3 Vec3::operator-(const Vec3& o) const{return Sub(o);}
    const Vec3 Vec3::operator*(const float o) const{return Mult(o);}
    const Vec3 Vec3::operator/(const float o) const{return Div(o);}
    const Vec3 Vec3::operator^(const Vec3& o) const{return tangent(o);}
    float Vec3::operator*(const Vec3& o) const{return Dot(o);}
}