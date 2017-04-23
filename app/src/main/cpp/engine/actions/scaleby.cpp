//
//  ScaleBy.cpp
//
//  Created by Francisco Ruiz.
//
//

#include "engine/actions/scaleBy.h"
#include "engine/graphics/spritenode.h"

namespace engine
{
    namespace Actions
    {
        ScaleBy* ScaleBy::Create(float time, const utils::Vec2& amount)
        {
            ScaleBy* res = new ScaleBy();
            res->_duration = time;
            res->_targetScale = amount;
            return res;
        }

        ScaleBy* ScaleBy::Create(float time, float amount)
        {
            ScaleBy* res = new ScaleBy();
            res->_duration = time;
            res->_targetScale = utils::Vec2(amount, amount);
            return res;
        }

        ScaleBy::~ScaleBy()
        {

        }

        ScaleBy::ScaleBy()
        {

        }

        void ScaleBy::Update(float dt)
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

        void ScaleBy::Start(graphics::SpriteNode* target)
        {
            _node = target;
            _elapsed = 0.0f;
            _originalScale = _node->GetScale();
            _distance = _targetScale.length();
            _direction = _targetScale.normalized();
            _targetScale = _originalScale + _targetScale;
        }
    }
}