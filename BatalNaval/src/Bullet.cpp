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
	bullet.circlelShape.setFillColor(sf::Color::Color(34, 51, 59));
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

void MovingBullet(Bullet& bullet, float deltaTime, bool turn, sf::Vector2f& velocity, std::string direction)
{
	float gravityScaleY = 500.f;
	

	sf::Vector2f gravity {0 , gravityScaleY};
	if (direction == "N") 
	{
		velocity += gravity * deltaTime + sf::Vector2f(0, 0.01);
	}
	else if (direction == "S") 
	{
		velocity += gravity * deltaTime * 1.1f;
	}
	else if (direction == "E") 
	{
		velocity.y += gravity.y * deltaTime;
		velocity.x += gravity.x * deltaTime + 0.001f;
	}
	else if (direction == "W") 
	{
		velocity.y += gravity.y * deltaTime;
		velocity.x -= gravity.x * deltaTime + 0.001f;
	}

	sf::Vector2f pos = (velocity * deltaTime);

	//std::cout << velocity.x << '\n';

	bullet.circlelShape.move(pos);
}