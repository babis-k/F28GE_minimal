#include "Scene.h"
#include "Entity.h"
#include "Component.h"

namespace gel
{
    void SceneNode::AcceptVisitor(SceneNodeVisitor& visitor)
    {
        // ... Do something here
        visitor.Visit(*this);

        // And process the children
        for (auto& child : children)
            child.AcceptVisitor(visitor);
    }

    sf::Transform SceneNode::GetCombinedTransform() const
    {
        // if we don't have an entity, stop here and return a default transform
        auto spEntity = entity.lock();
        if (spEntity == nullptr)
            return {};
        // extract the transform matrix
        auto transform = spEntity->GetTransformable().getTransform();
        // if we have a parent, then append that into the multiplication "list" recursively
        if (parent != nullptr)
            return parent->GetCombinedTransform() * transform;
        else
            return transform;
    }

    void SceneNode::AddChild(const SceneNode& child)
    {
        children.push_back(child);
        UpdateParentsRecursive();
    }

    void SceneNode::UpdateParentsRecursive()
    {
        for (auto& ch : children)
        {
            ch.parent = this;
            ch.UpdateParentsRecursive();
        }
    }

    void SceneNode::RemoveByEntity(std::weak_ptr<Entity> e)
    {
        auto pEntity = e.lock().get();
        int iFound = -1;
        for (int i = 0; i < children.size(); ++i)
        {
            if (children[i].GetEntity().lock().get() == pEntity)
            {
                iFound = i;
                break;
            }
        }
        if (iFound >= 0)
        {
            children.erase(children.begin() + iFound);
            UpdateParentsRecursive();
        }
        else
        {
            for (auto& child : children)
                child.RemoveByEntity(e);
        }
    }

    SceneNode* SceneNode::FindChild(const Entity& e)
    {
        if (&e == entity.lock().get())
            return this;
        else
        {
            for (auto& c : children)
            {
                auto ret = c.FindChild(e);
                if (ret != nullptr)
                    return ret;
            }
        }
        return nullptr;
    }
}