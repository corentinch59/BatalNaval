#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

bool TestCollision(sf::ConvexShape batal, sf::CircleShape& bullet){
    bullet.setOrigin(sf::Vector2f(bullet.getRadius() / 2, bullet.getRadius() / 2));


    sf::FloatRect boundingBox = batal.getGlobalBounds();

    std::vector<sf::Vector2f> pointVector;
    int nbpoint = 5;

    pointVector.clear();
    pointVector.push_back(sf::Vector2f(bullet.getPosition().x + bullet.getRadius() / 2, bullet.getPosition().y));
    pointVector.push_back(sf::Vector2f(bullet.getPosition().x - bullet.getRadius() / 2, bullet.getPosition().y));
    pointVector.push_back(sf::Vector2f(bullet.getPosition().x, bullet.getPosition().y + bullet.getRadius()));
    pointVector.push_back(sf::Vector2f(bullet.getPosition().x, bullet.getPosition().y - bullet.getRadius() / 2));
    pointVector.push_back(bullet.getPosition());


    //DU CODE A FINIR POUR CLEAN
    //float angle;
    //float ratio;
    //    for(int i = 0; i < nbpoint; i++)
    //    {
    //        ratio = i / nbpoint; // tend vers 1
    //        angle = 2 * 3.14159265358979323846f * ratio; // angle qui fait le tour du cercle
    //        
    //        pointVector.push_back(sf::Vector2f(bullet.getPosition().x + bullet.getRadius() / 2, bullet.getPosition().y));
    //        cube.transform.position = new Vector3(Mathf.Cos(angle) * bullet.getRadius(), Mathf.Sin(angle) * bullet.getRadius()); //un Carre a chaque angle 
    //        
    //    }


    for (int i = 0; i < nbpoint; i++)
    {
        if (boundingBox.contains(pointVector[i]))
        {
            return true;
        }
    }
    return false;
}


bool TestWaterCollision(sf::RectangleShape water, sf::CircleShape& bullet) {

    sf::FloatRect boundingBox = water.getGlobalBounds();

    if (boundingBox.contains(bullet.getPosition()))
    {
        return true;
    }
    return false;
}

//void OnCollision(bool& playerTurn, Bullet* p_bullet,Batal player1, Batal player2, float rangeX, sf::RenderWindow& window) {
//
//
//    if (playerTurn)
//    {
//        if (p_bullet != nullptr && !TestCollision(player2.hull.hullShape, p_bullet->circlelShape)) {
//            MovingBullet(*p_bullet, rangeX, !playerTurn, window);
//        }
//        else {
//
//            player2.health--;
//            std::cout << "TOUCHE " << player2.health << '\n';
//
//            colided = true;
//            p_bullet = nullptr;
//            playerTurn = !playerTurn;
//            TestGameOver(player1, player2);
//        }
//    }
//}