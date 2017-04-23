//
//  DelayTime.cpp
//
//  Created by Francisco Ruiz5.
//
//

#include "engine/actions/delaytime.h"

namespace engine
{
    namespace Actions
    {
        DelayTime* DelayTime::Create(float time)
        {
            DelayTime* res = new DelayTime();
            res->_duration = time;
            return res;
        }

        DelayTime::~DelayTime()
        {

        }

        DelayTime::DelayTime()
        {

        }
    }
}