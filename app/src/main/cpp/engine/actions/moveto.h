//
//  MoveTo.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef MOVETO_H
#define __MovMOVETO_HeTo__

#include "engine/actions/action.h"
#include "engine/utils/vec2.h"

namespace engine
{
    namespace Actions
    {
        class MoveTo : public Action
        {

        public:

            static MoveTo* Create(float time, const utils::Vec2& destination);
            virtual ~MoveTo();

            virtual void Update(float dt) override;
            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            MoveTo();
            MoveTo(const MoveTo&) = delete;
            MoveTo& operator=(const MoveTo&) = delete;

            float _speed;
            float _distance;
            utils::Vec2 _direction;
            utils::Vec2 _destination;
            utils::Vec2 _origin;
        };

        typedef utils::ref_ptr<MoveTo> MoveToPtr;
    }
}
#endif // MOVETO_H
