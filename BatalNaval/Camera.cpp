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