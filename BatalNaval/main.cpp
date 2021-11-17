#include <iostream>
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Camera.h"
#include "Graphismes.h"
#include "Bullet.h"
#include "Collision.h"
#include "GameOver.h"

void Gamefunction(bool& quit, bool& restart, sf::RenderWindow& window);

int main()
{
    bool quit = false;
    bool restart = false;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "BatalNaval", sf::Style::Default, settings);
    
    while (!quit){
        restart = false;

        while (!quit && !restart){
            Gamefunction(quit, restart, window);
        }
    }  
}

void Gamefunction(bool& quit, bool& restart, sf::RenderWindow& window) {

    std::list<sf::CircleShape> wavesEffect;
    std::list<sf::CircleShape> voidEffect;

    Bullet* p_bullet = new Bullet;

	float angleR = 90.f;
    //valeur entre 0 et 1
	float pos1 = 0.2f;
    float pos2 = 0.2f;
	int numberOfWaves = 17;
	bool isUp = true;
    bool isPlayer1Turn = true;
    bool isGameOver = false;

    // Initialise everything below

	Batal player1 = CreateBatal(100.0f, 450.0f, 2, 3);
	Batal player2 = CreateBatal(1700.0f, 450.0f, 2, 4);
    FlipBatal(player2);
    Canon canon1 = CreateCanon(player1);
    Canon canon2 = CreateCanon(player2);
    FlipCanon(canon2);
    Uwater water = CreateWater();


    sf::View view;//(sf::Vector2f(350.f, 300.f), sf::Vector2f(300.f, 200.f));
    view.setCenter(sf::Vector2f(400.0f, 300.f));
    view.setSize(sf::Vector2f(800.f, 600.f));

    window.setView(view);

    bool goingLeft = true;
    bool cameraIsMoving = false;
    bool colided = false;

    sf::Clock clock;
    sf::Clock clock2;

    sf::Vector2f posBatalOne = sf::Vector2f(player1.position.x + 300.f, player1.position.y - 150.f);
    sf::Vector2f posBatalTwo = sf::Vector2f(1400.0f, player1.position.y - 150.f);
    sf::Vector2f target = posBatalOne;
    sf::Vector2f CameraPos = view.getCenter();
    sf::Vector2f velocity(0, -150.f);

    WavesCreator(numberOfWaves, wavesEffect, voidEffect);

    sf::Font font;
    font.loadFromFile(getAssetsPath() + "\\arial.ttf");

    GameOverTxt gameOvertxts = CreateGameOver();
    gameOvertxts.GameOver.setFont(font);
    gameOvertxts.Replay.setFont(font);
    gameOvertxts.PlayerName.setFont(font);

    //Game loop
    while (window.isOpen() && !restart) {
        sf::Event event;
        float deltaTime = clock.getElapsedTime().asSeconds();
        float trueDeltaTime = clock2.getElapsedTime().asSeconds();
        clock2.restart();
        
        MovingCam(window, view, CameraPos, target, deltaTime, cameraIsMoving);

        if (!colided)
        {
			if (isPlayer1Turn) 
            {
				//test collision avec le player2
				if (OnCollision(isPlayer1Turn, p_bullet, player2, water, trueDeltaTime, window, velocity, clock) || TestWaterCollision(water.water, p_bullet->circlelShape)) {
					colided = true;
					p_bullet = nullptr;
					isPlayer1Turn = !isPlayer1Turn;
					TestGameOver(player1, player2, isGameOver);
				}
			}
			else {
				//test collision avec le player1
				if (OnCollision(isPlayer1Turn, p_bullet, player1, water, trueDeltaTime, window, velocity, clock) || TestWaterCollision(water.water, p_bullet->circlelShape)) {
					colided = true;
					p_bullet = nullptr;
					isPlayer1Turn = !isPlayer1Turn;
					TestGameOver(player1, player2, isGameOver);
				}
			}
        }

        if (isGameOver)
        {
            DisplayGameOver(player1, gameOvertxts, view);
        }

        while (window.pollEvent(event)) {

            // Process any input event here
            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                quit = true;
                break;

            case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
				{

				}
                break;

            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space && !cameraIsMoving && !isGameOver)
                {
                    target = Direction(goingLeft, posBatalOne, posBatalTwo);
                    clock.restart();
                    CameraPos = view.getCenter();

                    p_bullet = new Bullet;
                    CreatingBullet(*p_bullet, canon1, canon2, pos1, isPlayer1Turn, window);

                    colided = false;
                    cameraIsMoving = true;

                    velocity = sf::Vector2f(500, -500);
                    float angleCanon;
                    if (isPlayer1Turn)
                    {
                        angleCanon = canon1.base.getRotation();
                    }
                    else
                    {
                        angleCanon = canon2.base.getRotation() + 180.f;
                    }
                    std::cout << angleCanon << '\n';
                    angleCanon = angleCanon *(3.1415f * 2.f)/360.f;
                    velocity = sf::Vector2f(cos(angleCanon), sin(angleCanon)) * 800.f;
                }
                if (event.key.code == sf::Keyboard::R && isGameOver)
                {
                    restart = true;
                }
                break;
            default: break;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (isPlayer1Turn)
            {
                Aiming(pos1, isUp, -angleR, trueDeltaTime, canon1);
            }
            else
            {
                Aiming(pos2, isUp, angleR, trueDeltaTime, canon2);
            }
        }
        window.clear();
        // Whatever I want to draw goes here

        DrawWater(water, window);
        WavesDrawing(wavesEffect, voidEffect, window);
        DrawBatal(player1, window);
        DrawBatal(player2, window);
        DrawCanon(canon1, window);
        DrawCanon(canon2, window);
        if (p_bullet != nullptr)
        {
            DrawBullet(*p_bullet, window);
        }
        DrawGameOver(gameOvertxts, window);

        window.display();
    }
}