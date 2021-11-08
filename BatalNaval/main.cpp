
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
    // Initialise everything below

    sf::CircleShape circle; // Déclaration de "circle" (sans affectation)
    circle.setRadius(100.0f);
    circle.setPosition(100.0f, 100.0f);
    circle.setFillColor(sf::Color::Red); // Appel de méthode qui travaille sur "circle"


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

