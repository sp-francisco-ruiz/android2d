//
// Created by fjruiz.
//
#ifndef ANDROIDWINDOW_H
#define ANDROIDWINDOW_H

#include <android/native_window.h>
#include <memory>

#include "engine/iwindow.h"
#include "platform/oglesrenderer.h"

namespace platform
{
    class AndroidWindow : public engine::IWindow
    {

    public:
        AndroidWindow();
        virtual ~AndroidWindow();

        void SetWindow(ANativeWindow* window);
        ANativeWindow* GetNativeWindow();

        void Initialize() override;
        void Dispose() override;
        engine::IRenderer& GetRenderer() override;

    private:
        ANativeWindow *_window;
        OGLESRenderer _renderer;
    };
}
#endif // ANDROIDWINDOW_H