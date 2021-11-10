#include <SFML/Graphics.hpp>
#include <iostream>

bool TestCollision(sf::ConvexShape batal, sf::CircleShape& bullet) {

    bullet.setOrigin(sf::Vector2f(bullet.getRadius() / 2, bullet.getRadius() / 2));

    sf::FloatRect boundingBox = batal.getGlobalBounds();

    std::vector<sf::Vector2f> pointVector;
    int nbpoint = 5;

    pointVector.push_back(sf::Vector2f(bullet.getPosition().x + bullet.getRadius() / 2, bullet.getPosition().y));

    pointVector.push_back(sf::Vector2f(bullet.getPosition().x - bullet.getRadius() / 2, bullet.getPosition().y));

    pointVector.push_back(sf::Vector2f(bullet.getPosition().x, bullet.getPosition().y + bullet.getRadius()));

    pointVector.push_back(sf::Vector2f(bullet.getPosition().x, bullet.getPosition().y - bullet.getRadius() / 2));

    pointVector.push_back(bullet.getPosition());


    for (int i = 0; i < nbpoint; i++)
    {
        if (boundingBox.contains(pointVector[i]))
        {
            std::cout << pointVector[i].x << ", " << pointVector[i].y <<  " index : " << i << '\n';
            return true;
        }
    }
    return false;
}