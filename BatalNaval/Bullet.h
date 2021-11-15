#pragma once
#include "Graphismes.h"

struct Bullet {
	Position position;
	sf::CircleShape circlelShape;
	float speed;
};

void CreatingBullet(Bullet& bullet, Canon& canon1, Canon& canon2, float pos, bool turn, sf::RenderWindow& window);
void DrawBullet(Bullet& bullet, sf::RenderWindow& window);
void MovingBullet(Bullet& bullet, float& rangeX, bool turn, sf::RenderWindow& window);