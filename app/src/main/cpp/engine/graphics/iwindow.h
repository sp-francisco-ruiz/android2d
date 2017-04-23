//
//  IWindow.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef IWINDOW_H
#define IWINDOW_H

#include "engine/utils/referenced.h"
#include "engine/graphics/scene.h"

namespace engine
{
    namespace graphics
    {
        class IWindow : public utils::Referenced
        {

        public:
            IWindow() {}
            virtual ~IWindow() {}
            virtual bool Init() = 0;
            virtual void Dispose() = 0;

            virtual float GetWidth() const = 0;
            virtual float GetHeight() const = 0;
            virtual void RenderScene(Scene* scene) = 0;
        };
        typedef utils::ref_ptr<IWindow> IWindowPtr;
    }
}
#endif // IWINDOW_H
