#pragma once
#include <list>
#include "batal.h"

struct Canon
{
	sf::RectangleShape canon;
	sf::CircleShape roue;
};

struct Uwater 
{
	sf::RectangleShape water;
};

Uwater CreateWater();
void DrawWater(Uwater& water, sf::RenderWindow& window);
Canon CreateCanon(Batal& player);
void FlipCanon(Batal& player, Canon& canon);
void WavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves);
void Aiming(float& pos, float& upLimit, float& downLimit, bool& isUp, float& rangeX, float& angleR, bool& turn, Canon& canon1, Canon& canon2);
void WavesDrawing(std::list<sf::CircleShape>& wavesEffect, std::list<sf::CircleShape>& voidEffect, sf::RenderWindow& window);
void DrawCanon(Canon& canon, sf::RenderWindow& window);