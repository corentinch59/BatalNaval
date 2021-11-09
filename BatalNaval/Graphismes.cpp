#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"

void Graphismes()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Graphisme");
	// Initialise everything below
	//sf::CircleShape wave;
	//wave.setRadius(50.0f); // Appel de m�thode qui travaille sur "circle"
	//wave.setPosition(100, 420);
	//wave.setFillColor(sf::Color::Blue);

	sf::RectangleShape Uwater(sf::Vector2f(800.0f, 200.0f));
	Uwater.setPosition(0.f, 450.f);
	Uwater.setFillColor(sf::Color::Blue);

	sf::RectangleShape Canon(sf::Vector2f(100.0f, 50.0f));
	Canon.setPosition(400.f, 100.f);
	Canon.setFillColor(sf::Color::Yellow);

	float angleR = 1.f;
	float upLimit = 4.f;
	float downLimit = -4.f;
	float pos = 0;
	bool isUp = true;


    // Game loop
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			// Process any input event here
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				if(pos < upLimit && isUp)
				{
					Canon.rotate(-angleR);
					pos += 0.1f;
					if (pos >= upLimit)
					{
						isUp = false;
					}
				}
				else if(pos > downLimit && !isUp)
				{
					Canon.rotate(angleR);
					pos -= 0.1f;
					if (pos < downLimit)
					{
						isUp = true;
					}
				}
			}
		}
		window.clear();
		window.draw(Uwater);
		window.draw(Canon);
		window.display();
	}
}







