#ifndef F28GE_COMPONENT_H
#define F28GE_COMPONENT_H

#include <SFML/Graphics.hpp>

namespace cgc
{
    // Player input
    struct InputComponent
    {
        virtual ~InputComponent() = default;
    };

    // AI logic
    struct LogicComponent
    {
        virtual ~LogicComponent() = default;
    };

    // audio information
    struct AudioComponent
    {
        virtual ~AudioComponent() = default;
    };

    // graphics information
    struct GraphicsComponent
    {
        virtual ~GraphicsComponent() = default;
        virtual sf::Vector2f Size() const = 0;
    };

    // physics information
    struct PhysicsComponent
    {
        virtual ~PhysicsComponent() = default;
    };


    // --------------------------
    // A few simple components
    // --------------------------


    struct SimplePhysicsComponent : public PhysicsComponent
    {
        sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f acceleration = sf::Vector2f(0.0f, 0.0f);
        bool affectedByGravity = true;
    };

    struct SimpleSpriteComponent : public GraphicsComponent
    {
        std::string textureName;
        sf::IntRect textureRect;
        sf::RectangleShape rectangleShape;

        sf::Vector2f Size() const override { return rectangleShape.getSize();}
    };

    struct SimpleCircleShapeComponent : public GraphicsComponent
    {
        sf::CircleShape circleShape;

        sf::Vector2f Size() const override { return sf::Vector2f( circleShape.getRadius()*2, circleShape.getRadius()*2);}
    };

    struct SimpleTilemapComponent : public GraphicsComponent
    {
        std::string textureName;
        // The other properties
        std::vector<sf::RectangleShape> sprites;

        sf::Vector2f Size() const override { return sprites.back().getSize() + sprites.back().getPosition();}
    };
}

#endif //F28GE_COMPONENT_H
