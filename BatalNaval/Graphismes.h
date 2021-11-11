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
void WavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves);
void Aiming(float& pos, float& upLimit, float& downLimit, bool& isUp, float& rangeX, float& angleR, Canon& canon);
void WavesDrawing(std::list<sf::CircleShape>& wavesEffect, std::list<sf::CircleShape>& voidEffect, sf::RenderWindow& window);
void CreatingBullet(sf::CircleShape& bullet, Canon& canon, bool isUp, float pos, sf::RenderWindow& window);
void MovingBullet(sf::CircleShape& bullet, float& rangeX, sf::RenderWindow& window);
void DrawCanon(Canon& canon, sf::RenderWindow& window);