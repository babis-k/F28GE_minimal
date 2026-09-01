#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

namespace gel
{
    class SceneNode;
    class Entity;

    // The scene node visitor interface
    class SceneNodeVisitor
    {
    public:
        virtual void Visit(SceneNode& sgn) = 0;
    };

    // A scene node. It can also represent the scene root (the entire scene)
    class SceneNode
    {
    public:
        // constructors
        SceneNode() = default;
        SceneNode(const std::weak_ptr<Entity>& zEntity) :entity(zEntity) {}

        // getters
        sf::Transform GetCombinedTransform() const;
        std::weak_ptr<Entity> GetEntity() const {return entity;}
        const SceneNode* GetParent() const { return parent; }

        // Add a child to this node
        void AddChild(const SceneNode& child);
        // The visitor will visit this node and all of our children
        void AcceptVisitor(SceneNodeVisitor& visitor);

        // Find the node that contains the given entity and remove it
        void RemoveByEntity(std::weak_ptr<Entity> e);
        // Find a child node given an entity
        SceneNode* FindChild(const Entity& e);
    private:
        // Call after performing add/remove operations in children
        void UpdateParentsRecursive();

        std::weak_ptr<Entity> entity;
        std::vector<SceneNode> children;

        const SceneNode* parent = nullptr;
    };
}

