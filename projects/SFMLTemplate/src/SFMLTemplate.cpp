#include <filesystem>
#include <SFML/Graphics.hpp>

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    sf::Vector2u windowSize(800, 600);
    sf::VideoMode videoMode(windowSize);
    sf::RenderWindow window(videoMode, "SFML Template");
    window.setVerticalSyncEnabled(true);

    // TODO: add some initialisation code here

    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            // TODO: add some event handling code here
        }

        // TODO: add some update logic here

        // Clear & Draw
        window.clear();

        // TODO: add your drawing commands here

        window.display();
    }
}