#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

bool TestCollision(sf::ConvexShape batal, sf::CircleShape& bullet);
bool TestWaterCollision(sf::RectangleShape water, sf::CircleShape& bullet);
