#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"

void Graphismes()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphisme");
    // Initialise everything below

    //sf::CircleShape circle; // Déclaration de "circle" (sans affectation)
    //circle.setRadius(100.0f);
    //circle.setPosition(100.0f, 100.0f);
    //circle.setFillColor(sf::Color::Red); // Appel de méthode qui travaille sur "circle"

    sf::RectangleShape Uwater(sf::Vector2f(800.0f, 200.0f));
	Uwater.setPosition(0.f, 450.f);
	Uwater.setFillColor(sf::Color::Blue);

	sf::RectangleShape Canon(sf::Vector2f(100.0f, 50.0f));
	Canon.setPosition(400.f, 100.f);
	Canon.setFillColor(sf::Color::Yellow);



    // Game loop
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			// Process any input event here
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}
		window.clear();
		window.draw(Uwater);
		window.draw(Canon);
		window.display();
	}
}








