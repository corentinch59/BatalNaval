#pragma once
#include "Graphismes.h"

struct Bullet {
	Position position;
	sf::CircleShape circlelShape;
};

void CreatingBullet(Bullet& bullet, Canon& canon1, Canon& canon2, float pos, bool turn, sf::RenderWindow& window);
void DrawBullet(Bullet& bullet, sf::RenderWindow& window);
void MovingBullet(Bullet& bullet, float time, bool turn, sf::Vector2f& velocity, std::string direction);