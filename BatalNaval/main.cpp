#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"

void DisplayGameLoop();

int main()
{
    //DisplayGameLoop();
    Graphismes();
}

void DisplayGameLoop()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
    // Initialise everything below




    // Game loop
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            // Process any input event here

            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Space)
                {
                }

            default: break;
            }
        }
        window.clear();
        // Whatever I want to draw goes here

        window.display();
    }

}

