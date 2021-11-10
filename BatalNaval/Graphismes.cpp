#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"
#include <list>

void wavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves);
void Firing();

void Graphismes()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Graphisme");
	// Initialise everything below

	sf::RectangleShape Uwater(sf::Vector2f(800.0f, 100.0f));
	Uwater.setPosition(0.f, 520.f);
	Uwater.setFillColor(sf::Color::Blue);

	sf::RectangleShape Canon(sf::Vector2f(70.0f, 50.0f));
	Canon.setPosition(200.f, 300.f);
	Canon.setFillColor(sf::Color::Yellow);

	std::list<sf::CircleShape> wavesEffect;
	std::list<sf::CircleShape> voidEffect;
	
	sf::CircleShape Bullet;

	float angleR = 1.f;
	float upLimit = 4.f;
	float downLimit = -4.f;
	float pos = 0;
	int numberOfWaves = 10;
	bool isUp = true;
	bool isFiring = false;
	bool vrari = true;

	wavesCreator(numberOfWaves, wavesEffect, voidEffect);

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
		auto it = wavesEffect.begin();
		while (it != wavesEffect.end())
		{
			window.draw((*it));
			it++;
		}
		auto it2 = voidEffect.begin();
		while (it2 != voidEffect.end())
		{
			window.draw((*it2));
			it2++;
		}

		window.draw(Canon);

		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
		{
			Bullet.setRadius(20);
			Bullet.setFillColor(sf::Color::Green);
			Bullet.setPosition(200.f, 300.f);
		}
		if (Bullet.getPosition().y <= 450.f)
		{
			Bullet.move(sf::Vector2f(0.01f, 0.01f));
			window.draw(Bullet);
		}

		window.display();
	}
}

void wavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves)
{
	int length = a;
	float posY = 480.f;
	float posX = -26.f;

	for(int i = 0; i < length; i++)
	{
		sf::CircleShape wave;
		wave.setRadius(43.0f);
		wave.setFillColor(sf::Color::Blue);
		wave.setPosition(posX, posY);
		posX += 130.f;
		
		waves.push_back(wave);
	}

	float voidPosX = 20.f;
	float voidPosY = 470.f;

	for (int j = 0; j < length; j++)
	{
		sf::CircleShape voidWave;
		voidWave.setRadius(42.0f);
		voidWave.setFillColor(sf::Color::Black);
		voidWave.setPosition(voidPosX, voidPosY);
		voidPosX += 130.f;

		voidWaves.push_back(voidWave);
	}
}









