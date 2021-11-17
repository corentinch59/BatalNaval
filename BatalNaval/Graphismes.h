#pragma once
#include <list>
#include "batal.h"
#include "Path.h"

const sf::Color skyColor = sf::Color::Color(194, 226, 247);
const sf::Color waterColor = sf::Color::Color(11, 29, 113);

struct Uwater 
{
	sf::RectangleShape water;
};

struct Wind {
	sf::RectangleShape arrowBody;
	sf::CircleShape arrowDirection;
	sf::Text windText;
};

struct  GameOverTxt
{
	sf::Text GameOver;
	sf::Text PlayerName;
	sf::Text Replay;
};

Uwater CreateWater();
void DrawWater(Uwater& water, sf::RenderWindow& window);
void WavesCreator(int a, std::list<sf::CircleShape>& waves ,std::list<sf::CircleShape>& voidWaves);
void Aiming(float& pos, bool& isUp, float angleSpeed, float deltaTime, Canon& canon);
void WavesDrawing(std::list<sf::CircleShape>& wavesEffect, std::list<sf::CircleShape>& voidEffect, sf::RenderWindow& window);
GameOverTxt CreateGameOver();
void DrawGameOver(GameOverTxt, sf::RenderWindow& window);
void DisplayGameOver(Batal player1, GameOverTxt& txts, sf::View view);
Wind WindDirection(sf::Font arial);
void drawWind(Wind& wind, sf::RenderWindow& window);