//
//  Scene.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef SCENE_H
#define SCENE_H

#include "engine/graphics/spritenode.h"

namespace engine
{
    namespace graphics
    {
        class Scene : public SpriteNode
        {
        public:
            static Scene* Create();
            virtual ~Scene();

        protected:
            virtual bool Init() override;

        private:
            Scene();
        };

        typedef utils::ref_ptr<Scene> ScenePtr;
    }
}
#endif // SCENE_H
