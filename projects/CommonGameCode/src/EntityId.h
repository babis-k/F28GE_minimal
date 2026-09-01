#pragma once

#include <vector>

namespace cgc
{
    // We can safely pass this object around, which can be understood and be evaluated to an entity by our entity manager
    struct EntityId
    {
        int index=-1;

        EntityId()=default;
        EntityId(int zIndex):index(zIndex){}

        bool operator==(const EntityId& other) const
        {
            return index == other.index;
        }

        bool IsValid() const
        {
            return index >= 0;
        }
    };
}

namespace std
{
    template<>
    struct hash<cgc::EntityId>
    {
        std::size_t operator()(const cgc::EntityId& id) const
        {
            return std::hash<int>{}(id.index);
        }
    };
}