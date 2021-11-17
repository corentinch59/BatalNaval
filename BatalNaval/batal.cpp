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

	// Affichage console
	std::cout << "Building a Batal with : " << '\n';
	std::cout << health <<" health points" << '\n';
	std::cout << "with a scale of : " << scale << '\n';
	std::cout << "position in x : " << x << '\n';
	std::cout << "position in y : " << y << '\n';

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
	std::cout << "Batal : Hull created" << '\n';

	// Construction du mât du batal
	sf::RectangleShape newMast(sf::Vector2f(-75 * newBatal.scale, 5 * newBatal.scale));
	newMast.setPosition(newBatal.position.x + 50 * newBatal.scale, newBatal.position.y);
	newMast.rotate(90);
	newMast.setFillColor(sf::Color(95, 40, 30, 255));
	newBatal.mast.mastShape = newMast;
	newBatal.mast.position = { newBatal.position.x + 50 * newBatal.scale , newBatal.position.y };
	std::cout << "Batal : Mast created" << '\n';


	// Construction de la voile du batal
	sf::CircleShape newSail(30 * newBatal.scale, 3);
	newSail.setFillColor(sf::Color::White);
	newSail.rotate(90);
	newSail.setPosition(newBatal.position.x + 95 * newBatal.scale, newBatal.position.y - 75 * newBatal.scale);
	newBatal.sail.sailShape = newSail;
	newBatal.sail.position = { newBatal.position.x + 95 * newBatal.scale, newBatal.position.y - 75 * newBatal.scale };
	std::cout << "Batal : Sail created" << '\n';
	
	std::cout << "Finished building Batal" << '\n';
	std::cout << "---" << '\n';

	return newBatal;
}

void FlipBatal(Batal& batal) {
	// Flip de la coque du batal
	batal.hull.hullShape.setScale(-1.0f, 1.0f);

	// Ajustement position du mât du batal
	UpdateMastPosition(batal.position.x - 50 * batal.scale, batal.position.y, batal);

	// Ajustement de la voile du batal
	UpdateSailPosition(batal.position.x - 100 * batal.scale, batal.position.y - 15 * batal.scale, batal);

	batal.isFlipped = true;
	std::cout << "Batal has been flipped" << '\n';
	std::cout << "---" << '\n';
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
	std::cout << "Started building a Cannon" << '\n';

	// Construction de la base du canon 
	sf::RectangleShape baseCanon(sf::Vector2f(35 * batal.scale, 10 * batal.scale));
	baseCanon.setPosition(batal.hull.hullShape.getPosition().x + 70 * batal.scale, batal.hull.hullShape.getPosition().y - 14 * batal.scale);
	baseCanon.setFillColor(sf::Color::Color(178, 178, 178));
	baseCanon.setOrigin(0, baseCanon.getSize().y / 2);
	newCanon.base = baseCanon;
	std::cout << "Cannon : base created" << '\n';


	// Construction de la roue du canon
	newCanon.roue.setRadius(8 * batal.scale);
	newCanon.roue.setPosition(newCanon.base.getPosition().x - newCanon.roue.getRadius(), newCanon.base.getPosition().y - 2 * batal.scale);
	newCanon.roue.setFillColor(sf::Color::Color(64, 50, 51, 255));
	std::cout << "Cannon : wheel created" << '\n';


	// Set de l'embout du canon
	newCanon.cannonballOrigin = { newCanon.base.getSize().x , newCanon.base.getSize().y / 2 };
	std::cout << "Cannon : mouthpiece set" << '\n';


	// Attachement au batal
	newCanon.batalAttached = &batal;
	std::cout << "Cannon : attached to Batal" << '\n';
	std::cout << "Finished creating Cannon" << '\n';
	std::cout << "---" << '\n';



	return newCanon;
}

void FlipCanon(Canon& canon) {
	canon.base.setScale(-1.0f, 1.0f);
	canon.base.setPosition(canon.batalAttached->hull.position.x - 170, canon.batalAttached->hull.position.y - 20);
	canon.roue.setPosition(canon.base.getPosition().x - canon.roue.getRadius(), canon.base.getPosition().y - 2 * canon.batalAttached->scale);
	std::cout << "Cannon has been flipped" << '\n';
	std::cout << "---" << '\n';

}

void DrawCanon(Canon& canon, sf::RenderWindow& window)
{
	window.draw(canon.base);
	window.draw(canon.roue);
}

BoatLife CreateLife(Batal& batal) {
	BoatLife newHeart;

	// Dessin du coeur
	sf::ConvexShape newHeartShape;
	newHeartShape.setPointCount(5);
	newHeartShape.setPoint(0, sf::Vector2f(0, 0));
	newHeartShape.setPoint(1, sf::Vector2f(-20, -30));
	newHeartShape.setPoint(2, sf::Vector2f(-10, -40));
	newHeartShape.setPoint(3, sf::Vector2f(-10, -40));
	newHeartShape.setPoint(4, sf::Vector2f(0, -30));
	newHeartShape.setFillColor(sf::Color::Red);
	newHeartShape.setPosition(sf::Vector2f(300, 300));
	newHeart.heartShape = newHeartShape;
	
	return newHeart;
}

void SetupHealthBoat(Batal& batal) {
	if (!batal.isFlipped) {
		for (int i = 0; i < batal.health; i++) {
			if (i == 0) {
				BoatLife test = CreateLife(batal);
				test.heartShape.setPosition(batal.position.x + 11 * batal.scale, batal.position.y + 30 * batal.scale);
				batal.lifeList.push_back(test);
			}
			else {
				BoatLife test = CreateLife(batal);
				if (i % 2 != 0) {
					test.heartShape.setScale(-1.0f, 1.0f);
					test.heartShape.setOrigin(-5 * batal.scale, 0);
					test.heartShape.setPosition(batal.lifeList[i-1].heartShape.getPosition().x + 10, batal.lifeList[i - 1].heartShape.getPosition().y);
				}
				else {
					test.heartShape.setPosition(batal.lifeList[i - 1].heartShape.getPosition().x + 30, batal.lifeList[i - 1].heartShape.getPosition().y);
				}
				batal.lifeList.push_back(test);
			}
		}
	}
	else {
		for (int i = 0; i < batal.health; i++) {
			if (i == 0) {
				BoatLife test = CreateLife(batal);
				test.heartShape.setPosition(batal.position.x - 26 * batal.scale, batal.position.y + 30 * batal.scale);
				test.heartShape.setScale(-1.0f, 1.0f);
				test.heartShape.setOrigin(-5 * batal.scale, 0);
				batal.lifeList.push_back(test);
			}
			else {
				BoatLife test = CreateLife(batal);
				if (i % 2 != 0) {
					test.heartShape.setPosition(batal.lifeList[i - 1].heartShape.getPosition().x + 30, batal.lifeList[i - 1].heartShape.getPosition().y);
				}
				else {
					test.heartShape.setScale(-1.0f, 1.0f);
					test.heartShape.setOrigin(-5 * batal.scale, 0);
					test.heartShape.setPosition(batal.lifeList[i - 1].heartShape.getPosition().x + 10, batal.lifeList[i - 1].heartShape.getPosition().y);
				}
				batal.lifeList.push_back(test);
			}
		}
	}
}

void DrawPvBatal(Batal& batal ,sf::RenderWindow& window) {
	if (batal.lifeList.size() > batal.health) {
		batal.lifeList.pop_back();
	}
	for (std::vector<BoatLife>::iterator it = batal.lifeList.begin(); it != batal.lifeList.end();) {
		window.draw(it->heartShape);
		it++;
	}
}



