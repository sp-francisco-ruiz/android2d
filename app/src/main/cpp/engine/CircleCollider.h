//
// Created by Francisco Ruiz.
//

#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include "engine/collider.h"
namespace engine
{
    class CircleCollider : public Collider
    {
    public:
        CircleCollider();

        float GetRadius() const;
        void SetRadius(float radius);
    private:
        float _radius;
    };
}
#endif //CIRCLECOLLIDER_H
