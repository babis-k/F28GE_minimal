#include "Entity.h"

#include "Component.h"
#include "EntitySignals.h"

namespace gel
{
    Entity::~Entity()
    {
        for (auto& component : components)
            if (component != nullptr)
            {
                signals::onComponentRemove(*this, component->GetComponentType());
                component = nullptr;
            }
    }

    std::weak_ptr<Component> Entity::FindComponent(ComponentType ct) const
    {
        std::weak_ptr<Component> wp;
        auto i = FindComponentIndex(ct);
        if (i >= 0)
            wp = components[i];
        return wp;
    }

    bool Entity::HasComponent(ComponentType ct) const
    {
        return !FindComponent(ct).expired();
    }

    std::weak_ptr<Component> Entity::AddComponent(ComponentType ct)
    {
        auto wp = FindComponent(ct);
        if (!wp.expired())
            return wp;
        auto sp = ComponentFactory(ct);
        components.push_back(sp);
        signals::onComponentAdded(*this, ct);
        return sp;
    }

    void Entity::RemoveComponent(ComponentType ct)
    {
        auto i = FindComponentIndex(ct);
        if (i >= 0)
        {
            signals::onComponentRemove(*this, ct);
            components[i] = nullptr;
        }
    }


    int Entity::FindComponentIndex(ComponentType ct) const
    {
        for (int i = 0; i < components.size(); ++i)
            if (components[i] != nullptr && components[i]->GetComponentType() == ct)
                return i;
        return -1;
    }
}
