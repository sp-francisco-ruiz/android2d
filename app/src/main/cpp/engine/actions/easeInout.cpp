//
//  EaseInOut.cpp
//
//  Created by Francisco Ruiz.
//
//

#include "engine/actions/easeinout.h"

namespace engine
{
    namespace Actions
    {
        EaseInOut* EaseInOut::Create(Action* action)
        {
            assert("created ease with a null action" && action);
            EaseInOut* res = new EaseInOut();
            res->_action = action;
            res->_duration = action->GetRemainingTime();
            return res;
        }

        EaseInOut::~EaseInOut()
        {

        }

        bool EaseInOut::IsFinished()
        {
            return _action->IsFinished();
        }

        void EaseInOut::Update(float dt)
        {
            _elapsed += dt;

            float timeToSend = 0.0f;

            float factor = _elapsed / _duration / 2.0f;
            if (factor < 1.0f)
            {
                timeToSend = _duration / 2.0f * factor * factor;
            }
            else
            {
                factor -= 1.0f;
                timeToSend = -_duration / 2.0f * (factor * (factor - 2.0f) - 1.0f);
            }

            _action->Update(timeToSend);
        }

        void EaseInOut::Start(graphics::SpriteNode* target)
        {
            _elapsed = 0.0f;
            _action->Start(target);
        }

        EaseInOut::EaseInOut()
        {

        }
    }
}