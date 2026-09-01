#pragma once

#include <sigslot/signal.hpp>

namespace cgc
{
    struct EntityId;

    // Signals
    namespace signals
    {
        // Make sure you add the "inline" keyword.

        // Parameter: the entity that was created
        inline sigslot::signal<EntityId> onEntityCreated;
        // Parameter: the entity that will be destroyed
        inline sigslot::signal<EntityId> onEntityDestroy;
        // Parameters: the entity that entered the tree, and the root entity of the tree
        inline sigslot::signal<EntityId, EntityId> onEntityEnteredTree;
        // Parameters: the entity that exits the tree, and the root entity of the tree
        inline sigslot::signal<EntityId, EntityId> onEntityExitTree;
        // Parameters: the parent entity and the child entity that was added
        inline sigslot::signal<EntityId, EntityId> onEntityChildAdded;
        // Parameters: the parent entity and the child entity that will be removed
        inline sigslot::signal<EntityId, EntityId> onEntityChildRemove;
    }
}