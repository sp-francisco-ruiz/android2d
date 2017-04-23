//
//  Scene.cpp
//
//  Created by Francisco Ruiz.
//
//
#include <algorithm>
#include <engine/platform/application.h>

#include "engine/graphics/scene.h"

namespace engine
{
    namespace graphics
    {
        Scene* Scene::Create()
        {
            Scene* res = new Scene();
            if (!res->Init())
            {
                if (res)
                {
                    delete res;
                }
                return nullptr;
            }
            return res;
        }

        bool Scene::Init()
        {
            if (SpriteNode::Init())
            {
                auto& window = platform::Application::GetSharedApp().GetWindow();
                _size = utils::Vec2(window.GetWidth(), window.GetHeight());
                return true;
            }
            return false;
        }

        Scene::Scene()
        {
        }

        Scene::~Scene()
        {

        }
    }
}
