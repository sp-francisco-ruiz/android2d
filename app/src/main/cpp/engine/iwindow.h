//
// Created by fjruiz.
//
#ifndef IWINDOW_H
#define IWINDOW_H

namespace engine
{
    class IRenderer;
    class IWindow
    {

    public:

        int GetWidth() const { return _width; }
        int GetHeight() const { return _height; }

        virtual void Dispose() = 0;
        virtual void Initialize() = 0;
        virtual IRenderer& GetRenderer() = 0;

    protected:
        int _width;
        int _height;
    };
}
#endif // IWINDOW_H