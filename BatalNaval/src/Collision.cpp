#include <iostream>
#include "Collision.h"

int TestCollision(sf::ConvexShape batal, sf::CircleShape& bullet, CriticalHit cc){
    bullet.setOrigin(sf::Vector2f(bullet.getRadius() / 2, bullet.getRadius() / 2));


    sf::FloatRect boundingBox = batal.getGlobalBounds();
    sf::FloatRect critiqueBox = cc.shape.getGlobalBounds();

    std::vector<sf::Vector2f> pointVector;
    int nbpoint = 5;

    pointVector.clear();
    pointVector.push_back(sf::Vector2f(bullet.getPosition().x + bullet.getRadius() / 2, bullet.getPosition().y));
    pointVector.push_back(sf::Vector2f(bullet.getPosition().x - bullet.getRadius() / 2, bullet.getPosition().y));
    pointVector.push_back(sf::Vector2f(bullet.getPosition().x, bullet.getPosition().y + bullet.getRadius()));
    pointVector.push_back(sf::Vector2f(bullet.getPosition().x, bullet.getPosition().y - bullet.getRadius() / 2));
    pointVector.push_back(bullet.getPosition());





    for (int i = 0; i < nbpoint; i++)
    {
        if (boundingBox.contains(pointVector[i]))
        {
            return 1;
        }
        if (critiqueBox.contains(pointVector[i]))
        {
            return 2;
        }
    }
    return 0;
}


bool TestWaterCollision(sf::RectangleShape water, sf::CircleShape& bullet) {

    sf::FloatRect boundingBox = water.getGlobalBounds();

    if (boundingBox.contains(bullet.getPosition()))
    {
        std::cout << "BATAL RATE" << '\n';
        return true;
    }
    return false;
}

bool OnCollision(bool playerTurn, Bullet* p_bullet, Batal& player, Uwater water,  float deltaTime, sf::RenderWindow& window, sf::Vector2f& startVelo, sf::Clock clock, CriticalHit& cc, std::string direction) {

    if (p_bullet != nullptr && TestCollision(player.hull.hullShape, p_bullet->circlelShape, cc) == 0) {
        MovingBullet(*p_bullet, deltaTime, !playerTurn, startVelo, direction);
        return false;
    }
    else if (p_bullet != nullptr && TestCollision(player.hull.hullShape, p_bullet->circlelShape, cc) == 1)
    {
        player.health--;
        std::cout << "BATAL TOUCHE" << '\n';
        return true;
    }
    else { 
        player.health -= 2;
        cc.shape.setFillColor(sf::Color::Color(255, 0, 0, 0));
        cc.shape.setPosition(0.f, 0.f);
        std::cout << "COUP CRITIQUE " << '\n';
        return true;
    }
}