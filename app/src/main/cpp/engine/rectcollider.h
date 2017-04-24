//
// Created by fjruiz.
//
#ifndef RECTCOLLIDER_H
#define RECTCOLLIDER_H

#include "engine/collider.h"

namespace engine
{
class RectCollider : public Collider
    {
    public:
        RectCollider();

        virtual void SetPosition(float x, float y) override;
        void SetSize(float width, float height);
        float GetWidth() const;
        float GetHeight() const;
        const utils::Vec4& GetAABB();
    private:
        bool _dirty;
        float _width;
        float _height;
        utils::Vec4 _aabb;
    };
}

#endif // RECTCOLLIDER_H
