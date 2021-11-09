#include <iostream>
#include <SFML/Graphics.hpp>
#include "Math.h"

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
    bool movingTheCam = false;

    sf::Clock clock;

    float movingTime = 3.0f;
    float ratio = 0.0f;
    float elapsedTime = 0.0f;


    sf::Vector2f posBatalOne = sf::Vector2f(200.0f, 150.0f);
    sf::Vector2f posBatalTwo = sf::Vector2f(700.0f, 150.0f);
    sf::Vector2f velocity = posBatalOne;
    sf::Vector2f target;
    sf::Vector2f CameraPos;

    // Game loop
    while (window.isOpen()) {
        sf::Event event;

        float deltaTime = clock.getElapsedTime().asSeconds();
        
        if (elapsedTime <= movingTime && movingTheCam)
        {
            elapsedTime = deltaTime;
            ratio = elapsedTime / movingTime;

            sf::Vector2f oldVelo = velocity;

            velocity = Lerp(CameraPos, target, ratio);

            sf::Vector2f newVelo = velocity;

            view.move(newVelo - oldVelo);
            window.setView(view);
        }
        

        while (window.pollEvent(event)) {

            // Process any input event here
            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Space)
                {
                    if (goingLeft)
                    {
                        target = posBatalTwo;
                        CameraPos = view.getCenter();
                        goingLeft = false;
                    }
                    else {
                        target = posBatalOne;
                        CameraPos = view.getCenter();
                        goingLeft = true;
                    }

                    movingTheCam = true;
                    elapsedTime = 0.0f;
                    clock.restart();
                }

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

