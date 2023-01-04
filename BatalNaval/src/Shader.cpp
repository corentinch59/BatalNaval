#include <SFML/Graphics.hpp>

void Shaders()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Graphisme");

	sf::RectangleShape Uwater(sf::Vector2f(800.0f, 200.0f));
	Uwater.setPosition(0.f, 450.f);
	Uwater.setFillColor(sf::Color::Blue);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			// Process any input event here
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}
		window.clear();
		window.draw(Uwater);
		window.display();
	}
}