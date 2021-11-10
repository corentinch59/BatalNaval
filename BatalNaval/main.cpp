#include <iostream>
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Camera.h"

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "BatalNaval");
    // Initialise everything below

    sf::CircleShape circle; // Déclaration de "circle" (sans affectation)
    circle.setRadius(100.0f);
    circle.setPosition(100.0f, 100.0f);
    circle.setFillColor(sf::Color::Red); // Appel de méthode qui travaille sur "circle"
    sf::CircleShape circle2; // Déclaration de "circle" (sans affectation)
    circle2.setRadius(100.0f);
    circle2.setPosition(600.0f, 100.0f);
    circle2.setFillColor(sf::Color::Blue);

    sf::View view;//(sf::Vector2f(350.f, 300.f), sf::Vector2f(300.f, 200.f));
    view.setCenter(sf::Vector2f(200.0f, 150.f));
    view.setSize(sf::Vector2f(400.0f , 300.f));

    window.setView(view);

    bool goingLeft = true;

    sf::Clock clock;

    sf::Vector2f posBatalOne = sf::Vector2f(200.0f, 150.0f);
    sf::Vector2f posBatalTwo = sf::Vector2f(700.0f, 150.0f);
    sf::Vector2f target = posBatalOne;
    sf::Vector2f CameraPos = view.getCenter();

    // Game loop
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
                break;
                
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space)
                {
                    target = Direction(goingLeft, posBatalOne, posBatalTwo);
                    clock.restart();
                    CameraPos = view.getCenter();
                }
                break;

            default: break;
            }
        }
        window.clear();
        // Whatever I want to draw goes here
        window.draw(circle);
        window.draw(circle2);

        window.display();
    }
}

