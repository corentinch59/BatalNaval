#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"


void WavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves)
{
	int length = a;
	float posY = 480.f;
	float posX = -96.f;

	for(int i = 0; i < length; i++)
	{
		sf::CircleShape wave;
		wave.setRadius(50.f);
		wave.setFillColor(sf::Color::Blue);
		wave.setPosition(posX, posY);
		posX += 127.f;
		
		waves.push_back(wave);
	}

	float voidPosX = -44.f;
	float voidPosY = 465.5f;

	for (int j = 0; j < length; j++)
	{
		sf::CircleShape voidWave;
		voidWave.setRadius(39.5f);
		voidWave.setFillColor(sf::Color::Black);
		voidWave.setPosition(voidPosX, voidPosY);
		voidPosX += 127.f;

		voidWaves.push_back(voidWave);
	}
}

void Aiming(float& pos, bool& isUp, float angleSpeed, float deltaTime, Canon& canon)
{
	float direction = 1.f;
	const float duration = 1.f;
	if(!isUp)
	{
		direction *= -1;
	}
  	canon.base.rotate(angleSpeed * direction * deltaTime);
	pos += direction * deltaTime / duration;

	//std::cout << pos << '\n';
	//pos est le % d'avancement
	
	if (pos >= 1 && isUp)
	{
		isUp = false;
	}
	else if (pos <= 0 && !isUp)
	{
		isUp = true;
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

Uwater CreateWater() 
{
	Uwater water;
	sf::RectangleShape New(sf::Vector2f(1950.0f, 100.0f));
	water.water = New;
	water.water.setPosition(0.f, 520.f);
	water.water.setFillColor(sf::Color::Blue);
	return water;
	
}

void DrawWater(Uwater& water, sf::RenderWindow& window)
{
	window.draw(water.water);
}