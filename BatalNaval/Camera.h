#pragma once
#include <SFML/Graphics.hpp>

void MovingCam(sf::RenderWindow& window, sf::View& view, sf::Vector2f from, sf::Vector2f to, float deltaTime);

sf::Vector2f Direction(bool& boolean, sf::Vector2f posOne, sf::Vector2f posTwo);