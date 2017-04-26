//
// Created by fjruiz.
//
#ifndef IGAME_H
#define IGAME_H

#include "engine/statictypes.h"

namespace engine
{
    class IRenderer;
    class IGame
    {

    public:
        virtual void Initialize(int width, int height) = 0;
        virtual void Dispose() = 0;
        virtual void Update(float deltaSeconds) = 0;
        virtual void Draw(IRenderer& renderer) = 0;
        virtual void ProcessInput(const std::list<InputType>& events) = 0;
    };
}
#endif // IGAME_H