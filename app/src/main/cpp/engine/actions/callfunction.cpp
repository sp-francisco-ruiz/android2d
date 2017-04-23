//
//  CallFunction.cpp
//
//  Created by Francisco Ruiz.
//
//

#include "engine/actions/callfunction.h"

namespace engine
{
    namespace Actions
    {
        CallFunction* CallFunction::Create(std::function<void()> callback)
        {
            CallFunction* res = new CallFunction();
            res->_callback = callback;
            return res;
        }

        CallFunction::~CallFunction()
        {
        }

        CallFunction::CallFunction() :_callback(nullptr)
        {
        }

        void CallFunction::Start(graphics::SpriteNode* target)
        {
            if (_callback)
            {
                _callback();
            }
        }
    }
}