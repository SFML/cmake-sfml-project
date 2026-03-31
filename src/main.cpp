#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Init_Boot.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
	windowInit( window );

	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Magenta );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}
		shape.setOrigin(shape.getGeometricCenter());
		sf::Vector2f windowSize(window.getSize().x, window.getSize().y);
		shape.setPosition( windowSize / 2.f );
		const sf::Angle angle1 = shape.getRotation();
		window.clear();
		shape.rotate(angle1 + sf::degrees(1));
		window.draw( shape );
		window.display();
	}
}
