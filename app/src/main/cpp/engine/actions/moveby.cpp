//
//  MoveBy.cpp
//
//  Created by Francisco Ruiz.
//
//

#include "engine/actions/moveby.h"
#include "engine/graphics/spritenode.h"

namespace engine
{
    namespace Actions
    {
        MoveBy* MoveBy::Create(float time, const utils::Vec2& amount)
        {
            MoveBy* res = new MoveBy();
            res->_duration = time;
            res->_destination = amount;
            return res;
        }

        MoveBy::~MoveBy()
        {

        }

        MoveBy::MoveBy()
        {

        }

        void MoveBy::Update(float dt)
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
                    _node->SetPosition(_origin + (_direction * (_distance * _elapsed / _duration)));
                }
            }
        }

        void MoveBy::Start(graphics::SpriteNode* target)
        {
            _node = target;
            _elapsed = 0.0f;
            _origin = _node->GetPosition();
            _distance = _destination.length();
            _direction = _destination.normalized();
            _destination = _origin + _destination;
        }
    }
}