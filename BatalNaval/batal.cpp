
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "batal.h"

Batal CreateBatal(float x, float y, float scale)
{
	Batal newBatal;

	newBatal.position.x = x;
	newBatal.position.y = y;

	// Construction de la coque du batal
	sf::ConvexShape newHull;
	newHull.setPointCount(7);
	newHull.setPoint(0, sf::Vector2f(0, 0));
	newHull.setPoint(1, sf::Vector2f(150 * scale, 0));
	newHull.setPoint(2, sf::Vector2f(150 * scale, 10 * scale));
	newHull.setPoint(3, sf::Vector2f(100 * scale, 10 * scale));
	newHull.setPoint(4, sf::Vector2f(70 * scale, 40 * scale));
	newHull.setPoint(5, sf::Vector2f(20 * scale, 50 * scale));
	newHull.setPoint(6, sf::Vector2f(-5 * scale, 20 * scale));
	newHull.setFillColor(sf::Color(125, 55, 40, 255));
	newHull.setPosition(newBatal.position.x, newBatal.position.y);
	newBatal.hull.hullShape = newHull;
	newBatal.hull.position = newBatal.position;

	// Construction du mât du batal
	sf::RectangleShape newMast(sf::Vector2f(-75 * scale, 5 * scale));
	newMast.setPosition(newBatal.position.x + 50 * scale, newBatal.position.y);
	newMast.rotate(90);
	newMast.setFillColor(sf::Color(95, 40, 30, 255));
	newBatal.mast.mastShape = newMast;
	newBatal.mast.position = { newBatal.position.x + 50 * scale , newBatal.position.y };

	// Construction de la voile du batal
	sf::CircleShape newSail(30 * scale, 3);
	newSail.setFillColor(sf::Color::White);
	newSail.rotate(90);
	newSail.setPosition(newBatal.position.x + 95 * scale, newBatal.position.y - 75 * scale);
	newBatal.sail.sailShape = newSail;

	return newBatal;
}

void RotateBatal(Batal& batal, float angle) {
	batal.hull.hullShape.rotate(angle);
	batal.mast.mastShape.rotate(angle);
	batal.sail.sailShape.rotate(angle);
}

void DrawBatal(Batal& batal, sf::RenderWindow& window) {
	window.draw(batal.hull.hullShape);
	window.draw(batal.mast.mastShape);
	window.draw(batal.sail.sailShape);
}