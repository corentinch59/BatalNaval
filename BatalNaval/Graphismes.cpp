#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"
#include <list>

void wavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves);

void Graphismes()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Graphisme");
	// Initialise everything below

	/*sf::CircleShape circle;
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(50);
	circle.setPosition(- 10.f, 430.f);*/

	sf::RectangleShape Uwater(sf::Vector2f(800.0f, 200.0f));
	Uwater.setPosition(0.f, 450.f);
	Uwater.setFillColor(sf::Color::Blue);

	sf::RectangleShape Canon(sf::Vector2f(100.0f, 50.0f));
	Canon.setPosition(400.f, 100.f);
	Canon.setFillColor(sf::Color::Yellow);

	std::list<sf::CircleShape> wavesEffect;
	std::list<sf::CircleShape> voidEffect;
	

	float angleR = 1.f;
	float upLimit = 4.f;
	float downLimit = -4.f;
	float pos = 0;
	bool isUp = true;

	wavesCreator(10, wavesEffect, voidEffect);

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
		window.display();
	}
}

void wavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves)
{
	
	int length = a;
	float posY = 420.f;
	float posX = -10.f;

	for(int i = 0; i < length; i++)
	{
		sf::CircleShape wave;
		wave.setRadius(45.0f);
		wave.setFillColor(sf::Color::Blue);
		wave.setPosition(posX, 430.f);
		posX += 150.f;
		
		waves.push_back(wave);
	}

	float voidPosX = 200.f;

	for (int j = 0; j < length; j++)
	{
		sf::CircleShape voidWave;
		voidWave.setRadius(45.0f);
		voidWave.setFillColor(sf::Color::Black);
		voidWave.setPosition(voidPosX, 430.f);
		voidPosX += 150.f;

		voidWaves.push_back(voidWave);
	}

}








