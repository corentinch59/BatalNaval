
#include "batal.h"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

Batal createBatal(float x, float y)
{
	sf::CircleShape* batal = new sf::CircleShape;

	batal->setFillColor(sf::Color::Red);
	batal->setRadius(100.0f);
	batal->setPosition(x, y);


}