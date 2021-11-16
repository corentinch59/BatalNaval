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
void Aiming(float& pos, bool& isUp, float angleSpeed, float deltaTime, Canon& canon);
void WavesDrawing(std::list<sf::CircleShape>& wavesEffect, std::list<sf::CircleShape>& voidEffect, sf::RenderWindow& window);
