#pragma once
#include <list>
#include "batal.h"

struct Uwater 
{
	sf::RectangleShape water;
};

Uwater CreateWater();
void DrawWater(Uwater& water, sf::RenderWindow& window);
void WavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves);
void Aiming(float& pos, float& upLimit, float& downLimit, bool& isUp, float& angleR, bool& turn, Canon& canon1, Canon& canon2);
void WavesDrawing(std::list<sf::CircleShape>& wavesEffect, std::list<sf::CircleShape>& voidEffect, sf::RenderWindow& window);
