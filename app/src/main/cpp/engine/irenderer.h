//
// Created by fjruiz.
//
#ifndef IRENDERER_H
#define IRENDERER_H

namespace engine
{
    class Sprite;
    class IWindow;
    class IRenderer
    {

    public:

        virtual void Initialize(IWindow* window) = 0;
        virtual void Dispose() = 0;
        virtual void StartFrame() = 0;
        virtual void DrawSprite(engine::Sprite& sprite) = 0;
        virtual void EndFrame() = 0;
        virtual unsigned int GetTextureId(const std::string& fileName) = 0;

        int GetWidth() const { return _width; }
        int GetHeight() const { return _height; }
    protected:
        int _width;
        int _height;
    };
}
#endif // RENDERER_H