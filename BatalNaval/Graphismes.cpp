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

void Aiming(float& pos, float& upLimit, float& downLimit, bool& isUp, float& rangeX, float& angleR, Canon& canon)
{
		if (pos < upLimit && isUp)
		{
			canon.canon.rotate(-angleR);
			pos += 0.1f;
			rangeX += 1;
			if (pos >= upLimit)
			{
				isUp = false;
			}
		}
		else if (pos > downLimit && !isUp)
		{
			canon.canon.rotate(angleR);
			pos -= 0.1f;
			rangeX -= 1;
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


Canon CreateCanon(Batal& player)
{
	Canon newCanon;
	sf::RectangleShape New(sf::Vector2f(70.0f, 20.0f));
	newCanon.canon = New;
	newCanon.canon.setOrigin(0, 10);

	newCanon.canon.setPosition(player.hull.position.x + 170, player.hull.position.y - 20);
	newCanon.canon.setFillColor(sf::Color::Color(64, 78, 77, 255));
	newCanon.roue.setRadius(17);
	newCanon.roue.setPosition(newCanon.canon.getPosition().x - 7, newCanon.canon.getPosition().y- 8);
	newCanon.roue.setFillColor(sf::Color::Color(64, 50, 51, 255));
	return newCanon;
}

Uwater CreateWater() 
{
	Uwater water;
	sf::RectangleShape New(sf::Vector2f(1600.0f, 100.0f));
	water.water = New;
	water.water.setPosition(0.f, 520.f);
	water.water.setFillColor(sf::Color::Blue);
	return water;
	
}

void DrawWater(Uwater& water, sf::RenderWindow& window)
{
	window.draw(water.water);
}

void DrawCanon(Canon& canon, sf::RenderWindow& window)
{
	window.draw(canon.canon);
	window.draw(canon.roue);
}