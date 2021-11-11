#include <iostream>
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Camera.h"
#include "batal.h"
#include "Graphismes.h"
#include "Collision.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "BatalNaval", sf::Style::Default, settings);

	std::list<sf::CircleShape> wavesEffect;
	std::list<sf::CircleShape> voidEffect;

	sf::CircleShape bullet;

	float angleR = 1.f;
	float upLimit = 4.f;
	float downLimit = -2.2f;
	float pos = 0;
	int numberOfWaves = 13;
	bool isUp = true;
	bool isFiring = false;
	bool vrari = true;

	// Initialise everything below

	Batal player1 = CreateBatal(100.f, 450.f, 2);
	Batal player2 = CreateBatal(1300.f, 450.f, 2);
    FlipBatal(player2);
	Canon canon1 = CreateCanon(player1);
    Canon canon2 = CreateCanon(player2);
	Uwater water = CreateWater();

    sf::View view;//(sf::Vector2f(350.f, 300.f), sf::Vector2f(300.f, 200.f));
    view.setCenter(sf::Vector2f(400.0f, 300.f));
    view.setSize(sf::Vector2f(800.f, 600.f));

    window.setView(view);

    bool goingLeft = true;

    sf::Clock clock;

    sf::Vector2f posBatalOne = sf::Vector2f(player1.position.x + 300.f, player1.position.y - 150.f);
    sf::Vector2f posBatalTwo = sf::Vector2f(1000.0f, player1.position.y - 150.f);
    sf::Vector2f target = posBatalOne;
    sf::Vector2f CameraPos = view.getCenter();

	WavesCreator(numberOfWaves, wavesEffect, voidEffect);
	
    //Game loop
    while (window.isOpen()) {
        sf::Event event;

        float deltaTime = clock.getElapsedTime().asSeconds();
        
        MovingCam(window, view, CameraPos, target, deltaTime);

        while (window.pollEvent(event)) {

            // Process any input event here
            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
				{
					Aiming(pos, upLimit, downLimit, isUp, angleR, canon1);
				}
                break;
                
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space)
                {
                    target = Direction(goingLeft, posBatalOne, posBatalTwo);
                    clock.restart();
                    CameraPos = view.getCenter();
					CreatingBullet(bullet,canon1,isUp, pos, window);
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
		
		MovingBullet(bullet, window);

        window.display();
    }
}