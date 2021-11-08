#pragma once

struct Position {
	float x;
	float y;
};

struct Batal {
	sf::CircleShape base;
	sf::RectangleShape mat;
	sf::CircleShape sail;
};

Batal createBatal(float x, float y);