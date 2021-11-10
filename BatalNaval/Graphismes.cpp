#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"



void Graphismes()
{
	//sf::RectangleShape Uwater(sf::Vector2f(800.0f, 100.0f));

	//sf::RectangleShape Canon(sf::Vector2f(70.0f, 50.0f));

	//std::list<sf::CircleShape> wavesEffect;
	//std::list<sf::CircleShape> voidEffect;

	//sf::CircleShape bullet;

	//float angleR = 1.f;
	//float upLimit = 4.f;
	//float downLimit = -4.f;
	//float pos = 0;
	//int numberOfWaves = 10;
	//bool isUp = true;
	//bool isFiring = false;
	//bool vrari = true;


	//sf::RenderWindow window(sf::VideoMode(800, 600), "Fenetre Principal");
	//// Initialise everything below

	//CreateCanon(Canon);
	//CreateWater(Uwater);

	//WavesCreator(numberOfWaves, wavesEffect, voidEffect);

 //   // Game loop
	//while (window.isOpen()) {

	//	sf::Event event;
	//	while (window.pollEvent(event)) {
	//		// Process any input event here
	//		if (event.type == sf::Event::Closed) {
	//			window.close();
	//		}
	//		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
	//		{
	//			Aiming(pos, upLimit, downLimit, isUp, angleR, Canon);
	//		}
	//	}
	//	window.clear();
	//
	//	window.draw(Uwater);
	//	WavesDrawing(wavesEffect, voidEffect, window);

	//	window.draw(Canon);

	//	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
	//	{
	//		CreatingBullet(bullet, window);
	//	}

	//	MovingBullet(bullet, window);

	//	window.display();
	//}
}

void WavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves)
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

void Aiming(float& pos, float& upLimit, float& downLimit, bool& isUp, float& angleR, sf::RectangleShape& Canon)
{
	
		if (pos < upLimit && isUp)
		{
			Canon.rotate(-angleR);
			pos += 0.1f;
			if (pos >= upLimit)
			{
				isUp = false;
			}
		}
		else if (pos > downLimit && !isUp)
		{
			Canon.rotate(angleR);
			pos -= 0.1f;
			if (pos < downLimit)
			{
				isUp = true;
			}
		}
}

void WavesDrawing(std::list<sf::CircleShape>& wavesEffect, std::list<sf::CircleShape>& voidEffect, sf::RenderWindow& window)
{
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
}

void CreatingBullet(sf::CircleShape& bullet, sf::RenderWindow& window) 
{
	bullet.setRadius(20);
	bullet.setFillColor(sf::Color::Green);
	bullet.setPosition(200.f, 300.f);
}

void MovingBullet(sf::CircleShape& bullet, sf::RenderWindow& window) 
{
	if (bullet.getPosition().y <= 500.f)
	{
		bullet.move(sf::Vector2f(0.01f, 0.01f));
		window.draw(bullet);
	}
}

void CreateCanon(sf::RectangleShape& Canon)
{
	Canon.setPosition(200.f, 300.f);
	Canon.setFillColor(sf::Color::Yellow);
}

void CreateWater(sf::RectangleShape& Uwater) 
{
	Uwater.setPosition(0.f, 520.f);
	Uwater.setFillColor(sf::Color::Blue);
}








