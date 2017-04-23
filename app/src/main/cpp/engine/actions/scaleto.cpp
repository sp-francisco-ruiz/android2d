//
//  ScaleTo.cpp
//
//  Created by Francisco Ruiz.
//
//

#include <limits>
#include "engine/actions/scaleto.h"
#include "engine/graphics/spritenode.h"

namespace engine
{
    namespace Actions
    {
        ScaleTo* ScaleTo::Create(float time, const utils::Vec2& target)
        {
            ScaleTo* res = new ScaleTo();
            res->_targetScale = target;
            res->_duration = time;
            return res;
        }

        ScaleTo* ScaleTo::Create(float time, float target)
        {
            ScaleTo* res = new ScaleTo();
            res->_targetScale = utils::Vec2(target, target);
            res->_duration = time;
            return res;
        }

        ScaleTo::~ScaleTo()
        {
        }

        ScaleTo::ScaleTo()
        {
        }

        void ScaleTo::Update(float dt)
        {
            if (_node)
            {
                _elapsed += dt;

                if (IsFinished())
                {
                    _node->SetScale(_targetScale);
                }
                else
                {
                    _node->SetScale(_originalScale + (_direction * (_distance * _elapsed / _duration)));
                }
            }
        }

        void ScaleTo::Start(graphics::SpriteNode* target)
        {
            _node = target;
            _elapsed = 0.0f;
            _originalScale = _node->GetScale();
            _direction = _targetScale - _originalScale;
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