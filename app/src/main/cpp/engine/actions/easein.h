//
//  EaseIn.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef EASEIN_H
#define EASEIN_H

#include "engine/actions/action.h"

namespace engine
{
    namespace Actions
    {
        class EaseIn : public Action
        {

        public:

            static EaseIn* Create(Action* action);

            virtual ~EaseIn();

            virtual bool IsFinished() override;
            virtual void Update(float dt) override;
            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            EaseIn();
            EaseIn(const EaseIn&) = delete;
            EaseIn& operator=(const EaseIn&) = delete;

            ActionPtr _action;
        };

        typedef utils::ref_ptr<EaseIn> EaseInPtr;
    }
}
#endif // EASEIN_H
