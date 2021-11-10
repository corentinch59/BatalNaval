#include <SFML/Graphics.hpp>

void TestCollision(sf::ConvexShape batal, sf::CircleShape& bullet) {

    bullet.setOrigin(sf::Vector2f(bullet.getRadius() / 2, bullet.getRadius() / 2));

    sf::FloatRect boundingBox = batal.getGlobalBounds();

    if (boundingBox.contains(bullet.getPosition()))
    {
        // collision!

    }
  
}