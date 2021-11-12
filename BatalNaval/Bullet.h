#pragma once
#include "Graphismes.h"

struct Bullet {
	Position position;
	sf::CircleShape circlelShape;
	float speed;
};

void CreatingBullet(Bullet& bullet, Canon& canon, float pos, sf::RenderWindow& window);
void DrawBullet(Bullet& bullet, sf::RenderWindow& window);
void MovingBullet(Bullet& bullet, float& rangeX, sf::RenderWindow& window);