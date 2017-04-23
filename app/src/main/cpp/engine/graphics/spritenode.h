//
//  SpriteNode.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef SPRITENODE_H
#define SPRITENODE_H

#include <vector>
#include <string>
#include <engine/utils/mat4.h>

#include "engine/utils/referenced.h"
#include "engine/actions/action.h"
#include "engine/utils/vec2.h"
#include "engine/utils/color.h"
#include "engine/graphics/texture.h"

namespace engine
{
    namespace utils
    {
        class TouchInfo;
    }
    namespace graphics
    {
        class SpriteNode : public utils::Referenced
        {
        public:
            enum class BlendMode
            {
                None,
                Blend,
                Add,
                Mult
            };

            static SpriteNode* Create(const std::string& name);
            static SpriteNode* Create();

            virtual ~SpriteNode();

            virtual bool InitWithTexture(const std::string& name);

            virtual void Update(float dt);

            void RunAction(Actions::Action* action);
            void StopAllActions();

            SpriteNode* GetParent() const;
            SpriteNode* GetChildAt(unsigned int index);
            const SpriteNode* GetChildAt(unsigned int index) const;

            const unsigned int NumChildren() const;

            bool AddChild(SpriteNode* other, int zOrder = 0);
            void RemoveChild(SpriteNode* other);
            int GetZOrder() const;
            void SetZOrder(int zOrder);

            void SetTintColor(float tintColor);
            virtual void SetTintColor(float r, float g, float b);
            virtual void SetTintColor(float r, float g, float b, float a);
            virtual void SetTintColor(const utils::Color& color);
            virtual void SetAlpha(float alpha);
            virtual void SetBlendMode(BlendMode mode);
            const utils::Color& GetLocalTintColor() const;
            utils::Color GetTintColor() const;
            BlendMode GetBlendMode() const;

            void SetRotation(float rotation);
            virtual void SetScale(const utils::Vec2& scale);
            void SetScale(float scale);
            void SetPosition(const utils::Vec2& position);
            const float GetRotation() const;
            const utils::Vec2& GetScale() const;
            const utils::Vec2& GetPosition() const;
            utils::Vec2 GetAnchoredPosition();
            utils::Vec2 GetWorldPosition();
            utils::Vec2 GetWorldAnchoredPosition();
            utils::Vec2 GetWorldScale() const;
            float GetWorldRotation();

            const utils::Vec2& GetAnchorPoint() const;
            void SetAnchorPoint(const utils::Vec2& anchor);

            void SetSize(const utils::Vec2& newSize);
            utils::Vec2 GetSize() const;
            utils::Vec2 GetWorldSize() const;
            bool GetWorldFlipX() const;
            bool GetWorldFlipY() const;

            const utils::Mat4& GetWorldTrans();

            void SetFlipX(bool flipped);
            void SetFlipY(bool flipped);
            bool GetFlipX() const;
            bool GetFlipY() const;

            bool IsVisible() const;
            void SetVisible(bool visible);

            Texture* GetTexture();
        protected:
            SpriteNode();
            SpriteNode(const SpriteNode&) = delete;
            SpriteNode& operator=(const SpriteNode&) = delete;

            virtual bool Init();
            void MarkDirty();

            SpriteNode* _parent;
            std::vector< utils::ref_ptr<SpriteNode> > _children;
            std::vector<Actions::ActionPtr> _actions;

            TexturePtr _texture;

            utils::Vec2 _anchor;
            utils::Vec2 _position;
            utils::Vec2 _scale;
            utils::Vec2 _size;
            utils::Color _tintColor;
            BlendMode _blendMode;
            float _rotation;
            int _zOrder;
            bool _visible;
            bool _touchable;

            bool _worldTransDirty;
            utils::Mat4 _transform;
        };

        typedef utils::ref_ptr<SpriteNode> SpriteNodePtr;
    }
}
#endif // SPRITENODE_H
