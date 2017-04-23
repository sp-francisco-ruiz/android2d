//
//  EaseInOut.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef EASEINOUT_H
#define EASEINOUT_H

#include "engine/actions/action.h"

namespace engine
{
    namespace Actions
    {
        class EaseInOut : public Action
        {

        public:

            static EaseInOut* Create(Action* action);

            virtual ~EaseInOut();

            virtual bool IsFinished() override;
            virtual void Update(float dt) override;
            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            EaseInOut();
            EaseInOut(const EaseInOut&) = delete;
            EaseInOut& operator=(const EaseInOut&) = delete;

            ActionPtr _action;
        };

        typedef utils::ref_ptr<EaseInOut> EaseInOutPtr;
    }
}
#endif // EASEINOUT_H
