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
		std::cout << "pos : " << pos << " posY :" << posY << '\n';
	}
	else
	{
		posY = pos * 9;
		std::cout << "pos : " << pos << " posY :" << posY << '\n';
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
	bullet.speed = 0.3f;
}


void DrawBullet(Bullet& bullet, sf::RenderWindow& window) {
	window.draw(bullet.circlelShape);
}

void MovingBullet(Bullet& bullet, float time, bool turn, sf::Vector2f& startVelo)
{
    float gravityScale = 0.07f;
    const float t = 0.5f;
    const float maxHeight = 0.09f;
    const float minHeight = -0.09f;
    const float smallerValue = 0.01f;

    sf::Vector2f pos(0.2f, 0);
    sf::Vector2f gravity{ 0, gravityScale };


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

    bullet.circlelShape.move(pos);
}