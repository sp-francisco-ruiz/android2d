//
//  EaseOut.cpp
//
//  Created by Francisco Ruiz .
//
//

#include "engine/actions/easeout.h"

namespace engine
{
    namespace Actions
    {
        EaseOut* EaseOut::Create(Action* action)
        {
            assert("created ease with a null action" && action);
            EaseOut* res = new EaseOut();
            res->_action = action;
            res->_duration = action->GetRemainingTime();
            return res;
        }

        EaseOut::~EaseOut()
        {
        }

        bool EaseOut::IsFinished()
        {
            return _action->IsFinished();
        }

        void EaseOut::Update(float dt)
        {
            _elapsed += dt;

            float factor = _elapsed / _duration;
            float timeToSend = -_duration * factor * (factor - 2.0f);
            _action->Update(timeToSend);
        }

        void EaseOut::Start(graphics::SpriteNode* target)
        {
            _elapsed = 0.0f;
            _action->Start(target);
        }

        EaseOut::EaseOut()
        {
        }
    }
}