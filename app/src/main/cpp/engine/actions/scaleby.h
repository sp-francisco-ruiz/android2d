//
//  ScaleBy.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef SCALEBY_H
#define SCALEBY_H

#include "engine/actions/action.h"
#include "engine/utils/vec2.h"

namespace engine
{
    namespace Actions
    {
        class ScaleBy : public Action
        {

        public:

            static ScaleBy* Create(float time, const utils::Vec2& amount);
            static ScaleBy* Create(float time, float amount);
            virtual ~ScaleBy();

            virtual void Update(float dt) override;
            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            ScaleBy();
            ScaleBy(const ScaleBy&) = delete;
            ScaleBy& operator=(const ScaleBy&) = delete;

            float _speed;
            float _distance;
            utils::Vec2 _direction;
            utils::Vec2 _targetScale;
            utils::Vec2 _originalScale;
        };

        typedef utils::ref_ptr<ScaleBy> ScaleByPtr;
    }
}
#endif // SCALEBY_H
