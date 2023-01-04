#pragma once

void MovingCam(sf::RenderWindow& window, sf::View& view, sf::Vector2f from, sf::Vector2f to, float deltaTime, bool& boolToReturn);

sf::Vector2f Direction(bool& boolean, sf::Vector2f posOne, sf::Vector2f posTwo);