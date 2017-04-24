//
// Created by fjruiz.
//
#ifndef COLLIDER_H
#define COLLIDER_H

#include "utils/vec4.h"
namespace engine
{
    class Collider
    {
    public:

        Collider();

        const utils::Vec4& GetPosition() const;
        virtual void SetPosition(float x, float y);

    protected:
        utils::Vec4 _position;
    };
}

#endif //COLLIDER_H
