//
//  Action.cpp
//
//  Created by Francisco Ruiz.
//
//

#ifndef ACTION_H
#define ACTION_H

#include "engine/utils/referenced.h"

#include <string>

namespace engine
{
    namespace graphics
    {
        class SpriteNode;
    }
    namespace Actions
    {
        class Action : public utils::Referenced
        {

        public:

            static Action* Create();

            virtual ~Action();

            virtual bool IsFinished();
            virtual void Update(float dt);
            virtual void Start(graphics::SpriteNode* target);

            virtual float GetRemainingTime();

        protected:
            Action();
            Action(const Action&) = delete;
            Action& operator=(const Action&) = delete;

            float _elapsed;
            float _duration;
            graphics::SpriteNode* _node;
        };

        typedef utils::ref_ptr<Action> ActionPtr;
    }
}
#endif // ACTION_H
