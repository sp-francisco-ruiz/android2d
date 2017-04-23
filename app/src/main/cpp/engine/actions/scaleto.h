//
//  ScaleTo.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef SCALETO_H
#define SCALETO_H

#include "engine/actions/action.h"
#include "engine/utils/vec2.h"

namespace engine
{
    namespace Actions
    {
        class ScaleTo : public Action
        {

        public:

            static ScaleTo* Create(float time, const utils::Vec2& target);
            static ScaleTo* Create(float time, float target);
            virtual ~ScaleTo();

            virtual void Update(float dt) override;
            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            ScaleTo();
            ScaleTo(const ScaleTo&) = delete;
            ScaleTo& operator=(const ScaleTo&) = delete;

            float _speed;
            float _distance;
            utils::Vec2 _direction;
            utils::Vec2 _targetScale;
            utils::Vec2 _originalScale;
        };

        typedef utils::ref_ptr<ScaleTo> ScaleToPtr;
    }
}
#endif // SCALETO_H
