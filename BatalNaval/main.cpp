
#include <iostream>
#include <SFML/Graphics.hpp>
#include "batal.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
    // Initialise everything below

    createBatal(100, 100);

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
        window.draw(circle);

        window.display();
    }



}

