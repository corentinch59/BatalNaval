
#include "batal.h"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

Batal CreateBatal(float x, float y)
{
	sf::CircleShape* batal = new sf::CircleShape;

	batal->setFillColor(sf::Color::Red);
	batal->setRadius(100.0f);
	batal->setPosition(x, y);
}

void DrawBatal(Batal& batal, sf::RenderWindow& window) {
	window.draw(batal.base);
	window.draw(batal.mat);
	window.draw(batal.sail);
}