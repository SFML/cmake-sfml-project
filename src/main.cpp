#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Init_Boot.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
	windowInit( window );

	sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
	sf::Vector2f windowSize(window.getSize().x, window.getSize().y);

	shape.setFillColor( sf::Color::Magenta );
	shape.setOrigin(shape.getGeometricCenter());
	shape.setPosition( windowSize / 2.f );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		const sf::Angle angle1 = shape.getRotation();
		window.clear();
		shape.rotate(angle1 + sf::degrees(.000002f));
		window.draw( shape );
		window.display();
	}
}
