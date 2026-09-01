#pragma once

#include <vector>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

namespace gel
{
    // Forward-declare component types and the Component class
    enum class ComponentType;
    class Component;

    // Simple class that stores a name, a transform, and a list of components
    class Entity
    {
    public:
        // Always provide a name
        Entity(const std::string& zName) :name(zName) {}

        // No default entities, no entity copying allowed. 
        Entity() = delete;
        Entity(const Entity&) = delete;
        Entity& operator=(const Entity&) = delete;

        // Custom destruction logic - we remove all components, and send messages while doing so
        ~Entity();

        //getters/setters
        const std::string& GetName() const { return name; }
        const sf::Transformable& GetTransformable() const { return transformable; }
        void SetTransformable(const sf::Transformable& zTransformable) { transformable = zTransformable; }

        // Get a component of the given type. Returns an expired/default weak pointer if not found
        std::weak_ptr<Component> FindComponent(ComponentType ct) const;

        // Check if we have a component of a given type
        bool HasComponent(ComponentType ct) const;

        // Add a component of a given type and return a weak pointer to it
        std::weak_ptr<Component> AddComponent(ComponentType ct);

        // Remove a component of a given type
        void RemoveComponent(ComponentType ct);

    private:

        // Return the index of a component type in our components list. Return -1 if not found
        int FindComponentIndex(ComponentType ct) const;

    private:
        std::string name;
        sf::Transformable transformable;
        std::vector<std::shared_ptr<Component>> components;
    };
}
