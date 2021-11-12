#pragma once
#include <SFML/Graphics.hpp>


struct Position {
	float x;
	float y;
};

struct Hull {
	sf::ConvexShape hullShape;
	Position position;
};

struct Mast {
	sf::RectangleShape mastShape;
	Position position;
};

struct Sail {
	sf::CircleShape sailShape;
	Position position;
};

struct Batal {
	Hull hull;
	Mast mast;
	Sail sail;
	Position position;
	float scale;
	float health;
};

struct Canon {
	sf::RectangleShape base;
	sf::CircleShape roue;
	sf::Vector2f cannonballOrigin;
	Batal* batalAttached;
};

// Partie Batal

Batal CreateBatal(float x, float y, float scale, float health);

void DrawBatal(Batal& batal, sf::RenderWindow& window);

void RotateBatal(Batal& batal, float angle);

void FlipBatal(Batal& batal);

void UpdateMastPosition(float x, float y, Batal& batal);

void UpdateSailPosition(float x, float y, Batal& batal);

// Partie Canon

Canon CreateCanon(Batal& batal);

void FlipCanon(Canon& canon);

void DrawCanon(Canon& canon, sf::RenderWindow& window);



