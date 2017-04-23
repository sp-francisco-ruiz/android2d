//
//  MoveBy.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef MOVEBY_H
#define MOVEBY_H

#include "engine/actions/action.h"
#include "engine/utils/vec2.h"

namespace engine
{
    namespace Actions
    {
        class MoveBy : public Action
        {

        public:

            static MoveBy* Create(float time, const utils::Vec2& amount);
            virtual ~MoveBy();

            virtual void Update(float dt) override;
            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            MoveBy();
            MoveBy(const MoveBy&) = delete;
            MoveBy& operator=(const MoveBy&) = delete;

            float _speed;
            float _distance;
            utils::Vec2 _direction;
            utils::Vec2 _destination;
            utils::Vec2 _origin;
        };

        typedef utils::ref_ptr<MoveBy> MoveByPtr;
    }
}
#endif // MOVEBY_H
