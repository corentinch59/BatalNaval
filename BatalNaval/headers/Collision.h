#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

int TestCollision(sf::ConvexShape batal, sf::CircleShape& bullet, CriticalHit cc);
bool TestWaterCollision(sf::RectangleShape water, sf::CircleShape& bullet);

bool OnCollision(bool playerTurn, Bullet* p_bullet, Batal& player, Uwater water, float time, sf::RenderWindow& window, sf::Vector2f& startVelo, sf::Clock clock, CriticalHit& cc, std::string direction);
