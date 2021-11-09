#pragma once

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
};

Batal CreateBatal(float x, float y, float scale);

void DrawBatal(Batal& batal, sf::RenderWindow& window);