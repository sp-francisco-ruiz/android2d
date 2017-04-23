//
//  CallFunction.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef CALLFUNCTION_H
#define CALLFUNCTION_H

#include "engine/actions/action.h"
#include <functional>

namespace engine
{
    namespace Actions
    {
        class CallFunction : public Action
        {

        public:

            static CallFunction* Create(std::function<void()> callback);
            virtual ~CallFunction();

            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            CallFunction();
            CallFunction(const CallFunction&) = delete;
            CallFunction& operator=(const CallFunction&) = delete;

            std::function<void()> _callback;
        };

        typedef utils::ref_ptr<CallFunction> CallFunctionPtr;
    }
}
#endif // CALLFUNCTION_H
