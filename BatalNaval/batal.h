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

Batal CreateBatal(float x, float y);

void DrawBatal(Batal& batal, sf::RenderWindow& window);