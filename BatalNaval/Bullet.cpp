#include "Bullet.h"
#include <iostream>

void CreatingBullet(Bullet& bullet, Canon& canon1, Canon& canon2, float pos, bool turn, sf::RenderWindow& window)
{
	float posX = 50.f;
	float posY = 0;

	//rajouter condition pour que ca marche avec le J2

	if (pos > 0 && !(0.1f < pos < 1))
	{
		posY = pos * 15;
	}
	else
	{
		posY = pos * 9;
	}
	if (pos - 1 < 0)
	{
		posY += 7;
	}

	bullet.circlelShape.setRadius(10);
	bullet.circlelShape.setFillColor(sf::Color::Green);
	if(turn)
	{
		bullet.position.x = canon1.base.getPosition().x + posX;
		bullet.position.y = canon1.base.getPosition().y - posY;
	}
	else
	{
		bullet.position.x = canon2.base.getPosition().x - posX;
		bullet.position.y = canon2.base.getPosition().y - posY;
	}


	bullet.circlelShape.setPosition(bullet.position.x, bullet.position.y);
}


void DrawBullet(Bullet& bullet, sf::RenderWindow& window) {
	window.draw(bullet.circlelShape);
}

void MovingBullet(Bullet& bullet, float time, bool turn, sf::Vector2f& startVelo, sf::Clock clock)
{
    float gravityScale = 0.3f;
    const float t = clock.getElapsedTime().asSeconds()/2.f;
    const float maxHeight = 0.2f;
    const float minHeight = -0.2f;
    const float smallerValue = 0.007f;

    sf::Vector2f pos(0.18f, 0);
    const sf::Vector2f gravity{ 0, gravityScale };

    if (!turn)
    {
        startVelo.y = startVelo.y + gravity.y * t;
        pos.y += startVelo.y * t;
        pos.y *= smallerValue;

        if (pos.y >= maxHeight)
        {
            pos.y = maxHeight;
        }
        else if (pos.y <= minHeight)
        {
            pos.y = minHeight;
        }
    }
    else
    {
        pos.x *= -1;
        startVelo.y += gravity.y * t;
        pos.y += startVelo.y * t;
        pos.y *= smallerValue;

        if (pos.y >= maxHeight)
        {
            pos.y = maxHeight;
        }
        else if (pos.y <= minHeight)
        {
            pos.y = minHeight;
        }
    }

    bullet.circlelShape.move(pos);
}