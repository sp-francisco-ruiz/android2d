//
//  Sequence.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "engine/actions/action.h"
#include <vector>

namespace engine
{
    namespace Actions
    {
        class Sequence : public Action
        {
        public:
            static const int kPlayForever;
            static const int kPlayOnce;

            enum class RepeatMode
            {
                Loop,     //restart from the beginning
                PingPong, //restart from the end
            };

            static Sequence* Create(std::vector<Action*> actions, 
                                    int repeatTimes = kPlayOnce,
                                    RepeatMode repeatMode = RepeatMode::Loop);

            virtual ~Sequence();

            virtual bool IsFinished() override;
            virtual void Update(float dt) override;
            virtual void Start(graphics::SpriteNode* target) override;
        protected:

            Sequence();
            Sequence(const Sequence&) = delete;
            Sequence& operator=(const Sequence&) = delete;

            int _current;
            int _remainingRepeatTimes;
            int _direction;
            RepeatMode _repeatMode;
            std::vector<ActionPtr> _actions;
        };
        
        typedef utils::ref_ptr<Sequence> SequencePtr;
    }
}
#endif // SEQUENCE_H
