#pragma once

#include <memory>

namespace gel
{
    // There's going to be an enum class with the different component types at some point. 
    enum class ComponentType;

    // Our base class
    class Component
    {
    public:
        // All components need to provide their component type
        virtual ComponentType GetComponentType() const = 0;
        // We're going to derive from this class, so mark destructor as virtual, and set it to default
        virtual ~Component() = default;
    };

    // Provide a prototype for a component factory; again, we don't have to implement it yet
    std::shared_ptr<Component> ComponentFactory(ComponentType ct);
}
