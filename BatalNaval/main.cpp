
#include <iostream>
#include <SFML/Graphics.hpp>
#include "batal.h"

float PI = 3.14159265358979323846;
float turnPerSecond = 1;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "BatalNaval", sf::Style::Default, settings);
    // Initialise everything below
    sf::Clock clock;

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

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


        window.display();
    }



}

