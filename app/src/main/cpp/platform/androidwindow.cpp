//
// Created by fjruiz.
//

#include "utils/lodepng.h"
#include "platform/androidwindow.h"

const std::string LOG_TAG("AndroidWindow");

namespace platform
{
    AndroidWindow::AndroidWindow()
    : _window(nullptr)
    {
    }

    AndroidWindow::~AndroidWindow()
    {
    }

    void AndroidWindow::SetWindow(ANativeWindow* window)
    {
        if(!window)
        {
            Dispose();
        }
        _window = window;
    }

    engine::IRenderer& AndroidWindow::GetRenderer()
    {
        return _renderer;
    }

    void AndroidWindow::Initialize()
    {
        _renderer.Initialize(this);
        _width = _renderer.GetWidth();
        _height = _renderer.GetHeight();
    }

    ANativeWindow* AndroidWindow::GetNativeWindow()
    {
        return _window;
    }

    void AndroidWindow::Dispose()
    {
        if(_window != nullptr)
        {
            _renderer.Dispose();
            ANativeWindow_release(_window);
            _window = nullptr;
        }
    }
}