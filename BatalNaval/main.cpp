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

    float angleR = 1.f;
    float upLimit = 4.f;
    float downLimit = -2.2f;
    float pos = 0;
    int numberOfWaves = 13;
    bool isUp = true;
    float rangeX = 675;
    bool isPlayer1Turn = true;
    bool isGameOver = false;

    // Initialise everything below

    Batal player1 = CreateBatal(100.0f, 450.0f, 2, 3);
    Batal player2 = CreateBatal(1300.0f, 450.0f, 2, 4);
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

    sf::Vector2f posBatalOne = sf::Vector2f(player1.position.x + 300.f, player1.position.y - 150.f);
    sf::Vector2f posBatalTwo = sf::Vector2f(1000.0f, player1.position.y - 150.f);
    sf::Vector2f target = posBatalOne;
    sf::Vector2f CameraPos = view.getCenter();

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


        MovingCam(window, view, CameraPos, target, deltaTime, cameraIsMoving);

        if (!colided) {
            if (isPlayer1Turn) {
                //test collision avec le player2
                if (OnCollision(isPlayer1Turn, p_bullet, player2, water, rangeX, window) || TestWaterCollision(water.water, p_bullet->circlelShape)) {
                    colided = true;
                    p_bullet = nullptr;
                    isPlayer1Turn = !isPlayer1Turn;
                    TestGameOver(player1, player2, isGameOver);
                }
            }
            else {
                //test collision avec le player1
                if (OnCollision(isPlayer1Turn, p_bullet, player1, water, rangeX, window) || TestWaterCollision(water.water, p_bullet->circlelShape)) {
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
                if (event.key.code == sf::Keyboard::Space && !isGameOver)
                {
                    Aiming(pos, upLimit, downLimit, isUp, rangeX, angleR, isPlayer1Turn, canon1, canon2);
                }
                break;

            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space && !cameraIsMoving && !isGameOver)
                {
                    target = Direction(goingLeft, posBatalOne, posBatalTwo);
                    clock.restart();
                    CameraPos = view.getCenter();

                    p_bullet = new Bullet;
                    CreatingBullet(*p_bullet, canon1, canon2, pos, isPlayer1Turn, window);

                    colided = false;
                    cameraIsMoving = true;
                }
                if (event.key.code == sf::Keyboard::R && isGameOver)
                {
                    restart = true;
                }
                break;
            default: break;
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