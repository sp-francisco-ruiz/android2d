//
//  Sequence.cpp
//
//  Created by Francisco Ruiz.
//
//

#include "engine/actions/sequence.h"

namespace engine
{
    namespace Actions
    {

        const int Sequence::kPlayForever = -1;
        const int Sequence::kPlayOnce = 1;

        bool Sequence::IsFinished()
        {
            return _remainingRepeatTimes == 0 && _actions.at(_current)->IsFinished();
        }

        void Sequence::Update(float dt)
        {
            if (IsFinished())
            {
                return;
            }

            _actions.at(_current)->Update(dt);
            if (_actions.at(_current)->IsFinished())
            {
                _current += _direction;
                if (_actions.size() <= _current || _current < 0)
                {
                     if(_remainingRepeatTimes > 0)
                     {
                        --_remainingRepeatTimes;
                     }
                     if(_remainingRepeatTimes != 0)
                     {
                        if(_repeatMode == RepeatMode::PingPong)
                        {
                            _direction = -_direction;
                            _current += _direction * 2;
                        }
                        else
                        {
                            _current = 0;
                        }
                     }
                     else
                     {
                         _current -= _direction;
                     }
                }
                if(_remainingRepeatTimes != 0)
                {
                    _actions.at(_current)->Start(_node); 
                }
            }
        }

        void Sequence::Start(graphics::SpriteNode* target)
        {
            _current = 0;
            _elapsed = 0;
            _node = target;
            if (_actions.size())
            {
                _actions.at(0)->Start(target);
            }
        }

        Sequence* Sequence::Create(std::vector<Action*> actions, 
                                   int repeatTimes, 
                                   RepeatMode repeatMode)
        {
            assert("empty actions vector" && actions.size() > 1);
            Sequence* retVal = new Sequence();
            for (Action* action : actions)
            {
                assert("added null action to sequence" && action);
                retVal->_actions.push_back(action);
            }
            retVal->_remainingRepeatTimes = repeatTimes;
            retVal->_repeatMode = repeatMode;
            return retVal;
        }

        Sequence::~Sequence() {}
        Sequence::Sequence() :_current(0), _direction(1)
        {
        }
    }
}