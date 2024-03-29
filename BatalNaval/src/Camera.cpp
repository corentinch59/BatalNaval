#include "Lerping.h"

void MovingCam(sf::RenderWindow& window, sf::View& view, sf::Vector2f from, sf::Vector2f to, float deltaTime, bool& boolToReturn){
    float movingTime = 1.6f;
    float ratio = 0.f;

    if (deltaTime <= movingTime)
    {
        //elapsedTime = deltaTime;
        ratio = deltaTime / movingTime;
        view.setCenter(Lerp(from, to, ratio));
        window.setView(view);
    }
    else boolToReturn = false;
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