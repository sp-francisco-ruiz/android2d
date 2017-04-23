//
//  MoveTo.cpp
//
//  Created by Francisco Ruiz.
//
//

#include <limits>

#include "engine/actions/moveto.h"
#include "engine/graphics/spritenode.h"

namespace engine
{
    namespace Actions
    {
        MoveTo* MoveTo::Create(float time, const utils::Vec2& destination)
        {
            MoveTo* res = new MoveTo();
            res->_destination = destination;
            res->_duration = time;
            return res;
        }

        MoveTo::~MoveTo()
        {
        }

        MoveTo::MoveTo()
        {
        }

        void MoveTo::Update(float dt)
        {
            if (_node)
            {
                _elapsed += dt;

                if (IsFinished())
                {
                    _node->SetPosition(_destination);
                }
                else
                {
                    _node->SetPosition(_origin + _direction * (_distance * _elapsed / _duration));
                }
            }
        }

        void MoveTo::Start(graphics::SpriteNode* target)
        {
            _node = target;
            _elapsed = 0.0f;
            _origin = _node->GetPosition();
            _direction = _destination - _origin;
            _distance = _direction.length();
            if (_distance < std::numeric_limits<float>::epsilon())
            {
                _elapsed = _duration;
            }
            else
            {
                _direction = _direction.normalized();
            }
        }
    }
}