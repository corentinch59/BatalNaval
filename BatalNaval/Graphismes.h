#pragma once
#include <list>


void Graphismes();

void CreateWater(sf::RectangleShape& Uwater);
void CreateCanon(sf::RectangleShape& Canon);
void WavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves);
void Aiming(float& pos, float& upLimit, float& downLimit, bool& isUp, float& angleR, sf::RectangleShape& Canon);
void WavesDrawing(std::list<sf::CircleShape>& wavesEffect, std::list<sf::CircleShape>& voidEffect, sf::RenderWindow& window);
void CreatingBullet(sf::CircleShape& bullet, sf::RenderWindow& window);
void MovingBullet(sf::CircleShape& bullet, sf::RenderWindow& window);