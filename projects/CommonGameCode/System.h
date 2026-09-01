#pragma once

namespace gel
{
    class SceneNode;

    class System
    {
    public:
        virtual ~System() = default;
        virtual void Initialize() {} // call when initializing our game. allocate resources, or connect to signals
        virtual void Destroy() {} // call before we end the game. release resources
        virtual void Update(SceneNode& scene, float zDeltaTime) {} // do something with the current scene, every frame
    };
}