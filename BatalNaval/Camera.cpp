#include "Math.h"
#include <SFML/Graphics.hpp>


void MovingCam(sf::RenderWindow& window, sf::View& view, sf::Vector2f from, sf::Vector2f to, float deltaTime){
    float movingTime = 3.0;
    float ratio = 0.f;

    if (deltaTime <= movingTime)
    {
        //elapsedTime = deltaTime;
        ratio = deltaTime / movingTime;
	    view.setCenter(Lerp(from, to, ratio));
	    window.setView(view);
    }
}

sf::Vector2f Direction(bool& boolean, sf::Vector2f posOne, sf::Vector2f posTwo) {

    if (boolean)
    {
        boolean = false;
        return posTwo;
    }
    else {
        boolean = true;
        return posOne;
    }
    //clock.restart();
    //CameraPos = view.getCenter();
}