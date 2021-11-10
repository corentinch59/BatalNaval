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
	sf::RectangleShape Uwater(sf::Vector2f(800.0f, 100.0f));
	sf::RectangleShape Canon(sf::Vector2f(70.0f, 20.0f));
	std::list<sf::CircleShape> wavesEffect;
	std::list<sf::CircleShape> voidEffect;

	sf::CircleShape bullet;

	float angleR = 1.f;
	float upLimit = 4.f;
	float downLimit = -2.2f;
	float pos = 0;
	int numberOfWaves = 10;
	bool isUp = true;
	bool isFiring = false;
	bool vrari = true;

	// Initialise everything below

	Batal player1 = CreateBatal(100.f, 450.f, 2);

	CreateCanon(Canon, player1);
	CreateWater(Uwater);
	

    sf::CircleShape circle; // Déclaration de "circle" (sans affectation)
    circle.setRadius(20.f);
    circle.setPosition(700.f, 150.f);
    circle.setOrigin(10.f, 10.f);
    circle.setFillColor(sf::Color::Red); // Appel de méthode qui travaille sur "circle".


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
	
    // Game loop
    while (window.isOpen()) {
        sf::Event event;

        float deltaTime = clock.getElapsedTime().asSeconds();
        
        MovingCam(window, view, CameraPos, target, deltaTime);

        if (TestCollision(player1.hull.hullShape, circle))
        {
        }
        else circle.move(-0.1f, 0.1f);

        while (window.pollEvent(event)) {

            // Process any input event here
            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
				{
					Aiming(pos, upLimit, downLimit, isUp, angleR, Canon);
				}
                break;
                
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space)
                {
                    target = Direction(goingLeft, posBatalOne, posBatalTwo);
                    clock.restart();
                    CameraPos = view.getCenter();
					CreatingBullet(bullet, window);
                }
                break;

            default: break;
            }
        }
        window.clear();
        // Whatever I want to draw goes here
        window.draw(circle);
		
		window.draw(Uwater);
		WavesDrawing(wavesEffect, voidEffect, window);
		DrawBatal(player1, window);
		window.draw(Canon);
		
		MovingBullet(bullet, window);

        window.display();
    }
}