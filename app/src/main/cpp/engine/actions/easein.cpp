//
//  EaseIn.cpp
//
//  Created by Francisco Ruiz.
//
//

#include "engine/actions/easein.h"

namespace engine
{
    namespace Actions
    {
        EaseIn* EaseIn::Create(Action* action)
        {
            assert("created ease with a null action" && action);
            EaseIn* res = new EaseIn();
            res->_action = action;
            res->_duration = action->GetRemainingTime();
            return res;
        }

        EaseIn::~EaseIn()
        {

        }

        bool EaseIn::IsFinished()
        {
            return _action->IsFinished();
        }

        void EaseIn::Update(float dt)
        {
            _elapsed += dt;

            float factor = _elapsed / _duration;
            float timeToSend = factor * factor * _duration;
            _action->Update(timeToSend);
        }

        void EaseIn::Start(graphics::SpriteNode* target)
        {
            _elapsed = 0.0f;
            _action->Start(target);
        }

        EaseIn::EaseIn()
        {

        }
    }
}