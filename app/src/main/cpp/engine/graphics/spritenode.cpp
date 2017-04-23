//
//  SpriteNode.cpp
//  KingTest
//
//  Created by Francisco Ruiz on 13/6/15.
//
//

#include <algorithm>
#include <engine/platform/application.h>

#include "engine/graphics/spritenode.h"
#include "engine/graphics/texturecache.h"

using namespace engine::utils;

namespace engine
{
    namespace graphics
    {
        SpriteNode::~SpriteNode()
        {
        }

        SpriteNode* SpriteNode::GetParent() const
        {
            return _parent;
        }

        SpriteNode* SpriteNode::GetChildAt(unsigned int index)
        {
            if (index >= _children.size())
            {
                return nullptr;
            }

            return _children.at(index).get();
        }

        const SpriteNode* SpriteNode::GetChildAt(unsigned int index) const
        {
            if (index >= _children.size())
            {
                return nullptr;
            }

            return _children.at(index).get();
        }

        SpriteNode* SpriteNode::Create(const std::string& filename)
        {
            SpriteNode* res = new SpriteNode();
            if (!res->InitWithTexture(filename))
            {
                delete res;
                return nullptr;
            }
            return res;
        }

        SpriteNode* SpriteNode::Create()
        {
            SpriteNode* res = new SpriteNode();
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

        bool SpriteNode::Init()
        {
            return true;
        }

        void SpriteNode::Update(float dt)
        {
            std::vector<Actions::ActionPtr> IsFinished;

            for (Actions::ActionPtr& action : _actions)
            {
                if (action.valid())
                {
                    action->Update(dt);
                    if (action->IsFinished())
                    {
                        IsFinished.push_back(action);
                    }
                }
                else
                {
                    IsFinished.push_back(action);
                }
            }

            for (Actions::ActionPtr& action : IsFinished)
            {
                _actions.erase(std::find(_actions.begin(), _actions.end(), action));
            }

            for (SpriteNodePtr& child : _children)
            {
                child->Update(dt);
            }
        }

        void SpriteNode::RunAction(Actions::Action* action)
        {
            _actions.push_back(action);
            action->Start(this);
        }

        void SpriteNode::StopAllActions()
        {
            _actions.clear();
        }

        bool SpriteNode::InitWithTexture(const std::string& filename)
        {
            _texture = platform::Application::GetSharedApp().GetTextureCache().GetTexture(filename);
            return _texture.valid();
        }

        void SpriteNode::SetTintColor(float tintColor)
        {
            SetTintColor(tintColor, tintColor, tintColor);
        }

        void SpriteNode::SetTintColor(const Color& other)
        {
            _tintColor = other;
        }

        void SpriteNode::SetTintColor(float r, float g, float b)
        {
            _tintColor.set(r, g, b);
        }

        void SpriteNode::SetTintColor(float r, float g, float b, float a)
        {
            _tintColor.set(r, g, b, a);
        }

        void SpriteNode::SetAlpha(float alpha)
        {
            _tintColor.setA(alpha);
        }

        const Color& SpriteNode::GetLocalTintColor() const
        {
            return _tintColor;
        }

        Color SpriteNode::GetTintColor() const
        {
            Color res = _tintColor;
            if (_parent != nullptr)
            {
                res *= _parent->GetTintColor();
            }
            return res;
        }

        void SpriteNode::SetBlendMode(BlendMode mode)
        {
            _blendMode = mode;
        }

        SpriteNode::BlendMode SpriteNode::GetBlendMode() const
        {
            return _blendMode;
        }

        SpriteNode::SpriteNode()
            : _parent(nullptr)
            , _zOrder(0)
            , _scale(1.0f, 1.0f)
            , _rotation(0.0f)
            , _visible(true)
            , _touchable(false)
            , _blendMode(BlendMode::Blend)
        {
        }

        const unsigned int SpriteNode::NumChildren() const
        {
            return static_cast<unsigned int>(_children.size());
        }

        bool SpriteNode::AddChild(SpriteNode* other, int zOrder)
        {
            if (other)
            {
                ref_ptr<SpriteNode> n = other;
                if (zOrder && !other->GetZOrder())
                {
                    other->_zOrder = zOrder;
                }
                other->_parent = this;
                _children.push_back(n);
                return true;
            }
            return false;
        }

        int SpriteNode::GetZOrder() const
        {
            if (_parent)
            {
                return _parent->GetZOrder() + _zOrder;
            }
            return _zOrder;
        }

        void SpriteNode::SetZOrder(int zOrder)
        {
            MarkDirty();
            _zOrder = zOrder;
        }

        void SpriteNode::RemoveChild(SpriteNode* other)
        {
            if (other)
            {
                for (SpriteNodePtr& ptr : _children)
                {
                    if (ptr.get() == other)
                    {
                        other->_parent = nullptr;
                        _children.erase(std::find(_children.begin(), _children.end(), ptr));
                        break;
                    }
                }
            }
        }

        void SpriteNode::SetRotation(float rotation)
        {
            MarkDirty();
            _rotation = rotation;
        }

        void SpriteNode::SetScale(const Vec2 &scale)
        {
            MarkDirty();
            _scale = scale;
        }

        void SpriteNode::SetScale(float scale)
        {
            SetScale(Vec2(scale, scale));
        }

        void SpriteNode::SetPosition(const Vec2 &position)
        {
            MarkDirty();
            _position = position;
        }

        const float SpriteNode::GetRotation() const
        {
            return _rotation;
        }

        const Vec2& SpriteNode::GetScale() const
        {
            return _scale;
        }

        const Vec2& SpriteNode::GetPosition() const
        {
            return _position;
        }

        Vec2 SpriteNode::GetSize() const
        {
            return Vec2(_size.x() * _scale.x(), _size.y() * _scale.y());
        }

        Vec2 SpriteNode::GetWorldSize() const
        {
            Vec2 scale = GetWorldScale();
            return Vec2(_size.x() * scale.x(), _size.y() * scale.y());
        }

        void SpriteNode::SetSize(const Vec2& newSize)
        {
            MarkDirty();
            _size = newSize;
        }

        Vec2 SpriteNode::GetAnchoredPosition()
        {
            Vec2 size = GetSize();
            return _position - (Vec2(_anchor.x() * size.x(), _anchor.y() * size.y()));
        }

        Vec2 SpriteNode::GetWorldPosition()
        {
            if (_parent)
            {
                return _parent->GetWorldPosition() + _position;
            }

            return _position;
        }

        Vec2 SpriteNode::GetWorldAnchoredPosition()
        {
            if (_parent)
            {
                return _parent->GetWorldPosition() + GetAnchoredPosition();
            }

            return GetAnchoredPosition();
        }

        const utils::Mat4& SpriteNode::GetWorldTrans()
        {
            if(_worldTransDirty)
            {
                Mat4 rotation;
                Mat4 position;
                Mat4 scale;

                rotation.Rotate(GetWorldRotation());
                auto anchoredPos = GetWorldAnchoredPosition();
                position.Translate(anchoredPos.x(), anchoredPos.y(), GetZOrder());
                auto worldScale = GetWorldScale() * GetWorldSize();

                _transform = position * scale * rotation;
                _worldTransDirty = false;
            }
            return _transform;
        }

        float SpriteNode::GetWorldRotation()
        {
            if (_parent)
            {
                return _parent->GetWorldRotation() + _rotation;
            }

            return _rotation;
        }

        Vec2 SpriteNode::GetWorldScale() const
        {
            if (_parent)
            {
                const Vec2& parents = _parent->GetWorldScale();
                return Vec2(parents[0] * _scale[0], parents[1] * _scale[1]);
            }

            return _scale;
        }

        const Vec2& SpriteNode::GetAnchorPoint() const
        {
            return _anchor;
        }

        void SpriteNode::SetAnchorPoint(const Vec2& anchor)
        {
            MarkDirty();
            _anchor = anchor;
        }

        bool SpriteNode::GetFlipX() const
        {
            return _scale.x() < 0.0f;
        }

        bool SpriteNode::GetFlipY() const
        {
            return _scale.y() < 0.0f;
        }

        bool SpriteNode::GetWorldFlipX() const
        {
            bool flipX = GetFlipX();
            if (_parent)
            {
                bool parentFlipped = _parent->GetFlipX();
                return parentFlipped && flipX ? false : parentFlipped || flipX;
            }

            return flipX;        
        }

        bool SpriteNode::GetWorldFlipY() const
        {
            bool flipY = GetFlipY();
            if (_parent)
            {
                bool parentFlipped = _parent->GetFlipY();
                return parentFlipped && flipY ? false : parentFlipped || flipY;
            }

            return flipY;
        }

        void SpriteNode::SetFlipX(bool flipped)
        {
            if (flipped && _scale[0] > 0 || !flipped && _scale[0] < 0)
            {
                _scale[0] = -_scale[0];
                MarkDirty();
            }
        }

        void SpriteNode::SetFlipY(bool flipped)
        {
            if (flipped && _scale[1] > 0 || !flipped && _scale[1] < 0)
            {
                _scale[1] = -_scale[1];
                MarkDirty();
            }
        }

        bool SpriteNode::IsVisible() const
        {
            return _visible;
        }

        void SpriteNode::SetVisible(bool visible)
        {
            _visible = visible;
        }

        void SpriteNode::MarkDirty()
        {
            if(!_worldTransDirty)
            {
                for(auto& child : _children)
                {
                    child->MarkDirty();
                }
                _worldTransDirty = true;
            }

        }

        Texture* SpriteNode::GetTexture()
        {
            return _texture.get();
        }
    }
}