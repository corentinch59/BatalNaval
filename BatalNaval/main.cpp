#include <iostream>
#include <SFML/Graphics.hpp>
#include "batal.h"
#include "Graphismes.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "BatalNaval", sf::Style::Default, settings);

	std::list<sf::CircleShape> wavesEffect;
	std::list<sf::CircleShape> voidEffect;

	sf::CircleShape bullet;

	float angleR = 1.f;
	float upLimit = 4.f;
	float downLimit = -2.2f;
	float pos = 0;
	int numberOfWaves = 13;
	bool isUp = true;
	bool isFiring = false;
	bool vrari = true;

	// Initialise everything below
	sf::Clock clock;

	Batal player1 = CreateBatal(100.f, 450.f, 2);
	Canon canon1 = CreateCanon(player1);
	Uwater water = CreateWater();
	

	WavesCreator(numberOfWaves, wavesEffect, voidEffect);

	// Game loop
	while (window.isOpen()) {

		sf::Event event;
		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
		while (window.pollEvent(event)) {
			// Process any input event here
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				Aiming(pos, upLimit, downLimit, isUp, angleR, canon1);
			}
		}
		window.clear();

		DrawWater(water, window);
		WavesDrawing(wavesEffect, voidEffect, window);
		DrawBatal(player1, window);
		DrawCanon(canon1, window);
		
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
		{
			CreatingBullet(bullet, window);
		}

		MovingBullet(bullet, window);

		window.display();
	}
}
