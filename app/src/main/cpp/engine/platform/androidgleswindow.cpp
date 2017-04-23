//
//  AndroidGLESWindow.cpp
//
//  Created by Francisco Ruiz.
//
//

#include <functional>
#include <algorithm>

#include "engine/platform/androidgleswindow.h"
#include "engine/graphics/texture.h"

using namespace engine::utils;

namespace
{
    bool sortNodes(engine::graphics::SpriteNode* a, engine::graphics::SpriteNode* b)
    {
        return a->GetZOrder() < b->GetZOrder();
    }
}

namespace engine
{
    namespace platform
    {
        float AndroidGLESWindow::GetWidth() const
        {
            return _renderer.GetWidth();
        }

        float AndroidGLESWindow::GetHeight() const
        {
            return _renderer.GetHeight();
        }

        void AndroidGLESWindow::RenderScene(graphics::Scene* scene)
        {
            std::vector<graphics::SpriteNode*> nodes_to_render, to_process, children;

            to_process.push_back(scene);
            graphics::SpriteNode* current = nullptr;

            while (to_process.size() > 0)
            {
                while (to_process.size() > 0)
                {
                    current = to_process.back();
                    to_process.pop_back();
                    if (current)
                    {
                        if (current->GetTexture() && current->IsVisible())
                        {
                            nodes_to_render.push_back(current);
                        }

                        for (unsigned int i = 0; i < current->NumChildren(); ++i)
                        {
                            children.push_back(current->GetChildAt(i));
                        }
                    }
                }

                while (children.size() > 0)
                {
                    to_process.push_back(children.back());
                    children.pop_back();
                }
            }

            std::sort(nodes_to_render.begin(), nodes_to_render.end(), sortNodes);

            _renderer.StartFrame();

            for (graphics::SpriteNode* node : nodes_to_render)
            {
                DrawNode(node);
            }

            _renderer.EndFrame();
        }

        void AndroidGLESWindow::DrawNode(graphics::SpriteNode* node)
        {
            _renderer.DrawSprite(*node);
        }

        bool AndroidGLESWindow::Init()
        {
            _renderer.Initialize();
            return true;
        }
        AndroidGLESWindow::AndroidGLESWindow()
            :_initialized(false)
            , _window(nullptr)
        {
        }

        void AndroidGLESWindow::Dispose()
        {
            _renderer.Destroy();
        }

        void AndroidGLESWindow::SetWindow(ANativeWindow *window)
        {
            _window = window;
            _renderer.SetWindow(window);
        }

        void AndroidGLESWindow::SetAssets(AAssetManager *assets)
        {
            _renderer.SetAssetManager(assets);
        }

        graphics::Texture* AndroidGLESWindow::LoadTexture(const std::string& name)
        {
            return _renderer.LoadTexture(name);
        }
    }
}