#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"

void DisplayGameLoop();

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fenetre Principal");
	sf::RectangleShape Uwater(sf::Vector2f(800.0f, 100.0f));
	sf::RectangleShape Canon(sf::Vector2f(70.0f, 50.0f));
	std::list<sf::CircleShape> wavesEffect;
	std::list<sf::CircleShape> voidEffect;

	sf::CircleShape bullet;

	float angleR = 1.f;
	float upLimit = 4.f;
	float downLimit = -4.f;
	float pos = 0;
	int numberOfWaves = 10;
	bool isUp = true;
	bool isFiring = false;
	bool vrari = true;

	// Initialise everything below

	CreateCanon(Canon);
	CreateWater(Uwater);

	WavesCreator(numberOfWaves, wavesEffect, voidEffect);

	// Game loop
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			// Process any input event here
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				Aiming(pos, upLimit, downLimit, isUp, angleR, Canon);
			}
		}
		window.clear();

		window.draw(Uwater);
		WavesDrawing(wavesEffect, voidEffect, window);
		window.draw(Canon);
		

		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
		{
			CreatingBullet(bullet, window);
		}

		MovingBullet(bullet, window);

		window.display();
	}
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

