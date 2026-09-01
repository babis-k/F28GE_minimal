#include "SFMLApplication.h"

#include <filesystem>

#include <SFML/Graphics.hpp>

namespace cgc
{
	void SFMLApplication::Run(int windowWidth, int windowHeight, const std::string& title)
	{
		sf::Vector2u windowSize(windowWidth, windowHeight);
		sf::VideoMode videoMode(windowSize);
        auto window = sf::RenderWindow(videoMode, title.c_str());
        window.setVerticalSyncEnabled(true);

        // Initialisation logic
		Init(window);

        sf::Clock clock;
        while (window.isOpen())
        {
            // Process events
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();

                // Event handling code here
                HandleEvent(event);
            }

            float dt = clock.restart().asSeconds();

            // Update logic
            Update(dt);

            // Clear & Draw
            window.clear();

            Render(window);

            window.display();
        }
	}


}