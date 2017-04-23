//
//  EaseOut.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef EASEOUT_H
#define EASEOUT_H

#include "engine/actions/action.h"

namespace engine
{
    namespace Actions
    {
        class EaseOut : public Action
        {

        public:

            static EaseOut* Create(Action* action);

            virtual ~EaseOut();

            virtual bool IsFinished() override;
            virtual void Update(float dt) override;
            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            EaseOut();
            EaseOut(const EaseOut&) = delete;
            EaseOut& operator=(const EaseOut&) = delete;

            ActionPtr _action;
        };

        typedef utils::ref_ptr<EaseOut> EaseOutPtr;
    }
}
#endif // EASEOUT_H
