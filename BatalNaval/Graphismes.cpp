#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphismes.h"


void WavesCreator(int a, std::list<sf::CircleShape>& waves, std::list<sf::CircleShape>& voidWaves)
{
	int length = a;
	float posY = 480.f;
	float posX = -96.f;

	for(int i = 0; i < length; i++)
	{
		sf::CircleShape wave;
		wave.setRadius(50.f);
		wave.setFillColor(waterColor);
		wave.setPosition(posX, posY);
		posX += 127.f;
		
		waves.push_back(wave);
	}

	float voidPosX = -44.f;
	float voidPosY = 465.5f;

	for (int j = 0; j < length; j++)
	{
		sf::CircleShape voidWave;
		voidWave.setRadius(39.5f);
		voidWave.setFillColor(skyColor);
		voidWave.setPosition(voidPosX, voidPosY);
		voidPosX += 127.f;

		voidWaves.push_back(voidWave);
	}
}

void Aiming(float& pos, bool& isUp, float angleSpeed, float deltaTime, Canon& canon)
{
	float direction = 1.f;
	const float duration = 1.f;
	if(!isUp)
	{
		direction *= -1;
	}
  	canon.base.rotate(angleSpeed * direction * deltaTime);
	pos += direction * deltaTime / duration;

	//std::cout << pos << '\n';
	//pos est le % d'avancement
	
	if (pos >= 1 && isUp)
	{
		isUp = false;
	}
	else if (pos <= 0 && !isUp)
	{
		isUp = true;
	}

}

void WavesDrawing(std::list<sf::CircleShape>& wavesEffect, std::list<sf::CircleShape>& voidEffect, sf::RenderWindow& window)
{
	auto it = wavesEffect.begin();
	while (it != wavesEffect.end())
	{
		window.draw((*it));
		it++;
	}
	auto it2 = voidEffect.begin();
	while (it2 != voidEffect.end())
	{
		window.draw((*it2));
		it2++;
	}
}

Uwater CreateWater() 
{
	Uwater water;
	sf::RectangleShape New(sf::Vector2f(4950.0f, 100.0f));
	water.water = New;
	water.water.setPosition(-1000.f, 520.f);
	water.water.setFillColor(waterColor);
	return water;
	
}

void DrawWater(Uwater& water, sf::RenderWindow& window)
{
	window.draw(water.water);
}

GameOverTxt CreateGameOver() {
	GameOverTxt txts;
	txts.GameOver.setScale(2, 2);
	return txts;
}

void DisplayGameOver(Batal player1, GameOverTxt& txts, sf::View view) {
	txts.GameOver.setString("GAME OVER");
	txts.Replay.setString("Press R to replay");

	if (player1.health > 0)
	{
		txts.PlayerName.setString("Player 1 Win");
	}
	else txts.PlayerName.setString("Player 2 Win");

	txts.GameOver.setPosition(view.getCenter() - sf::Vector2f(200, 200));
	txts.PlayerName.setPosition(view.getCenter() - sf::Vector2f(150, 100));
	txts.Replay.setPosition(view.getCenter() - sf::Vector2f(150, 50));
}

void DrawGameOver(GameOverTxt txt, sf::RenderWindow& window) {
	window.draw(txt.GameOver);
	window.draw(txt.Replay);
	window.draw(txt.PlayerName);
}

Wind WindDirection(std::string direction, sf::View view)
{
	Wind wind;
	wind.windText.setString(direction);
	wind.windText.setScale(1.8, 1.8);
	wind.windText.setPosition(view.getCenter() - sf::Vector2f(340, 250));
	wind.windText.setFillColor(sf::Color::Red);
	return wind;
}

void drawWind(Wind& wind, sf::RenderWindow& window)
{
	window.draw(wind.windText);
}

std::string RandomWind() 
{
	std::string direction = "";
	int number = rand() % 4 + 1;
	if (number == 1)
	{
		direction = "N";
	}
	else if (number == 2)
	{
		direction = "E";
	}
	else if (number == 3)
	{
		direction = "W";
	}
	else if (number == 4)
	{
		direction = "S";
	}
	
	return direction;
}