#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"

void Graphismes()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphisme");
    // Initialise everything below

    //sf::CircleShape circle; // D�claration de "circle" (sans affectation)
    //circle.setRadius(100.0f);
    //circle.setPosition(100.0f, 100.0f);
    //circle.setFillColor(sf::Color::Red); // Appel de m�thode qui travaille sur "circle"

    sf::RectangleShape Uwater(sf::Vector2f(800.0f, 200.0f));
	Uwater.setPosition(0.f, 450.f);
	Uwater.setFillColor(sf::Color::Blue);

	sf::RectangleShape Canon(sf::Vector2f(100.0f, 50.0f));
	Canon.setPosition(400.f, 100.f);
	Canon.setFillColor(sf::Color::Yellow);



    // Game loop
	while (window.isOpen()) {

void CreatingBullet(sf::CircleShape& bullet, Canon& canon, bool isUp, float pos, sf::RenderWindow& window) 
{
	float posX = 50.f;
	float posY = 0;

	//rajouter condition pour que ca marche avec le J2

	if(pos > 0 && !(0.1f < pos < 1))
	{
		posY = pos * 15;
		std::cout << "pos : " << pos << " posY :" << posY << '\n';
	}
	else
	{
		posY = pos * 9;
		std::cout << "pos : " << pos << " posY :" << posY << '\n';
	}
	if (pos - 1 < 0)
	{
		posY += 7;
	}

	bullet.setRadius(10);
	bullet.setFillColor(sf::Color::Green);
	bullet.setPosition(canon.canon.getPosition().x + posX, canon.canon.getPosition().y - posY);
}

void MovingBullet(sf::CircleShape& bullet, sf::RenderWindow& window) 
{
	if (bullet.getPosition().y <= 500.f)
	{
		bullet.move(sf::Vector2f(0.01f, 0.0f));
		window.draw(bullet);
	}
}

Canon CreateCanon(Batal& player)
{
	Canon newCanon;
	sf::RectangleShape New(sf::Vector2f(70.0f, 20.0f));
	newCanon.canon = New;
	newCanon.canon.setPosition(player.hull.position.x + 170, player.hull.position.y - 20);
	newCanon.canon.setFillColor(sf::Color::Color(64, 78, 77, 255));
	newCanon.roue.setRadius(17);
	newCanon.roue.setPosition(newCanon.canon.getPosition().x - 7, newCanon.canon.getPosition().y- 8);
	newCanon.roue.setFillColor(sf::Color::Color(64, 50, 51, 255));
	newCanon.canon.setOrigin(0, 10);
	return newCanon;
}



