#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Init_Boot.h"

int main()
{
	sf::RenderWindow window;
	windowInit( window, 768, 1024, 60, false, false );
	sf::Vector2f windowSize(window.getSize().x, window.getSize().y);

	/////TEST SHAPE SHIT/////
		sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
		shape.setFillColor( sf::Color::Magenta );
		shape.setOrigin(shape.getGeometricCenter());
		shape.setPosition( windowSize / 2.f );
	//////////////////////////

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

	/////MORE TEST SHAPE SHIT///////////
		const sf::Angle angle1 = shape.getRotation();
		shape.rotate(angle1 + sf::degrees(.000002f));

	/////////////////////////////

		window.clear(sf::Color::Blue);
		window.draw( shape );
		window.display();
	}
}
