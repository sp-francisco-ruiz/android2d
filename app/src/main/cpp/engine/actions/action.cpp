//
//  Action.cpp
//
//  Created by Francisco Ruiz.
//
//

#include "engine/actions/action.h"
#include "engine/graphics/spritenode.h"

namespace engine
{
    namespace Actions
    {
        Action* Action::Create()
        {
            return new Action();
        }

        void Action::Start(graphics::SpriteNode *target)
        {
            _node = target;
        }

        Action::~Action()
        {
        }

        Action::Action() :_elapsed(0.0f), _duration(0.0f)
        {
        }

        bool Action::IsFinished()
        {
            return GetRemainingTime() <= 0.0f;
        }

        float Action::GetRemainingTime()
        {
            return _duration - _elapsed;
        }

        void Action::Update(float dt)
        {
            _elapsed += dt;
        }
    }
}