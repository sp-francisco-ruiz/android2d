//
//  DelayTime.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef DELAYTIME_H
#define DELAYTIME_H

#include "engine/actions/action.h"

namespace engine
{
    namespace Actions
    {
        class DelayTime : public Action
        {

        public:

            static DelayTime* Create(float time);
            virtual ~DelayTime();
        protected:

            DelayTime();
            DelayTime(const DelayTime&) = delete;
            DelayTime& operator=(const DelayTime&) = delete;
        };

        typedef utils::ref_ptr<DelayTime> DelayTimePtr;
    }
}
#endif // DELAYTIME_H
