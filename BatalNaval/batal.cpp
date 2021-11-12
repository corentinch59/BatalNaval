#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "batal.h"


Batal CreateBatal(float x, float y, float scale, float health)
{
	Batal newBatal;

	newBatal.position.x = x;
	newBatal.position.y = y;
	newBatal.scale = scale;
	newBatal.health = health;

	// Construction de la coque du batal
	sf::ConvexShape newHull;
	newHull.setPointCount(7);
	newHull.setPoint(0, sf::Vector2f(0, 0));
	newHull.setPoint(1, sf::Vector2f(150 * newBatal.scale, 0));
	newHull.setPoint(2, sf::Vector2f(150 * newBatal.scale, 10 * newBatal.scale));
	newHull.setPoint(3, sf::Vector2f(100 * newBatal.scale, 10 * newBatal.scale));
	newHull.setPoint(4, sf::Vector2f(70 * newBatal.scale, 40 * newBatal.scale));
	newHull.setPoint(5, sf::Vector2f(20 * newBatal.scale, 50 * newBatal.scale));
	newHull.setPoint(6, sf::Vector2f(-5 * newBatal.scale, 20 * newBatal.scale));
	newHull.setFillColor(sf::Color(125, 55, 40, 255));
	newHull.setPosition(newBatal.position.x, newBatal.position.y);
	newBatal.hull.hullShape = newHull;
	newBatal.hull.position = newBatal.position;

	// Construction du mât du batal
	sf::RectangleShape newMast(sf::Vector2f(-75 * newBatal.scale, 5 * newBatal.scale));
	newMast.setPosition(newBatal.position.x + 50 * newBatal.scale, newBatal.position.y);
	newMast.rotate(90);
	newMast.setFillColor(sf::Color(95, 40, 30, 255));
	newBatal.mast.mastShape = newMast;
	newBatal.mast.position = { newBatal.position.x + 50 * newBatal.scale , newBatal.position.y };

	// Construction de la voile du batal
	sf::CircleShape newSail(30 * newBatal.scale, 3);
	newSail.setFillColor(sf::Color::White);
	newSail.rotate(90);
	newSail.setPosition(newBatal.position.x + 95 * newBatal.scale, newBatal.position.y - 75 * newBatal.scale);
	newBatal.sail.sailShape = newSail;
	newBatal.sail.position = { newBatal.position.x + 95 * newBatal.scale, newBatal.position.y - 75 * newBatal.scale };

	return newBatal;
}

void FlipBatal(Batal& batal) {
	// Flip de la coque du batal
	batal.hull.hullShape.setScale(-1.0f, 1.0f);

	// Ajustement position du mât du batal
	UpdateMastPosition(batal.position.x - 50 * batal.scale, batal.position.y, batal);

	// Ajustement de la voile du batal
	UpdateSailPosition(batal.position.x - 100 * batal.scale, batal.position.y - 15 * batal.scale, batal);
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

void UpdateMastPosition(float x, float y, Batal& batal) {
	batal.mast.mastShape.setPosition(x, y);
	sf::Vector2f mastpos = batal.mast.mastShape.getPosition();
	batal.mast.position = { mastpos.x, mastpos.y };
}

void UpdateSailPosition(float x, float y, Batal& batal) {
	batal.sail.sailShape.setPosition(x, y);
	batal.sail.sailShape.rotate(180);
	sf::Vector2f sailpos = batal.sail.sailShape.getPosition();
	batal.sail.position = { sailpos.x, sailpos.y };
}

Canon CreateCanon(Batal& batal)
{
	Canon newCanon;

	// Construction de la base du canon 
	sf::RectangleShape baseCanon(sf::Vector2f(35 * batal.scale, 10 * batal.scale));
	baseCanon.setPosition(batal.hull.hullShape.getPosition().x + 70 * batal.scale, batal.hull.hullShape.getPosition().y - 14 * batal.scale);
	baseCanon.setFillColor(sf::Color::Red);
	baseCanon.setOrigin(0, baseCanon.getSize().y / 2);
	newCanon.base = baseCanon;

	// Construction de la roue du canon
	newCanon.roue.setRadius(8 * batal.scale);
	newCanon.roue.setPosition(newCanon.base.getPosition().x - newCanon.roue.getRadius(), newCanon.base.getPosition().y - 2 * batal.scale);
	newCanon.roue.setFillColor(sf::Color::Color(64, 50, 51, 255));

	// Set de l'embout du canon
	newCanon.cannonballOrigin = { newCanon.base.getSize().x , newCanon.base.getSize().y / 2 };

	// Attachement au batal
	newCanon.batalAttached = &batal;

	return newCanon;
}

void FlipCanon(Canon& canon) {
	canon.base.setScale(-1.0f, 1.0f);
	canon.base.setPosition(canon.batalAttached->hull.position.x - 170, canon.batalAttached->hull.position.y - 20);
	canon.roue.setPosition(canon.base.getPosition().x - canon.roue.getRadius(), canon.base.getPosition().y - 2 * canon.batalAttached->scale);
}

void DrawCanon(Canon& canon, sf::RenderWindow& window)
{
	window.draw(canon.base);
	window.draw(canon.roue);
}



