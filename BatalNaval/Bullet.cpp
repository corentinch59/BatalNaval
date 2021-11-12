#include "Bullet.h"
#include <iostream>

void CreatingBullet(Bullet& bullet, Canon& canon1, Canon& canon2, float pos, bool& turn, sf::RenderWindow& window)
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
		bullet.position.x = canon1.canon.getPosition().x + posX;
		bullet.position.y = canon1.canon.getPosition().y - posY;
	}
	else
	{
		bullet.position.x = canon2.canon.getPosition().x - posX;
		bullet.position.y = canon2.canon.getPosition().y - posY;
	}


	bullet.circlelShape.setPosition(bullet.position.x, bullet.position.y);
	bullet.speed = 0.3f;
}


void DrawBullet(Bullet& bullet, sf::RenderWindow& window) {
	window.draw(bullet.circlelShape);
}

void MovingBullet(Bullet& bullet, float& rangeX, bool& turn, sf::RenderWindow& window)
{
	if (bullet.circlelShape.getPosition().y <= 500.f)
	{
		if(!turn)
		{
			//window.draw(bullet);
			if (bullet.circlelShape.getPosition().x < rangeX)
			{
				bullet.circlelShape.move(sf::Vector2f(bullet.speed, -bullet.speed));
			}
			else if (bullet.circlelShape.getPosition().x > rangeX)
			{
				bullet.circlelShape.move(sf::Vector2f(bullet.speed, bullet.speed));
			}
		}
		else
		{
			//window.draw(bullet);
			if (bullet.circlelShape.getPosition().x > rangeX)
			{
				bullet.circlelShape.move(sf::Vector2f(-bullet.speed, -bullet.speed));
			}
			else if (bullet.circlelShape.getPosition().x < rangeX)
			{
				bullet.circlelShape.move(sf::Vector2f(-bullet.speed, bullet.speed));
			}
		}
	}
}