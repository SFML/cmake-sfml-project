#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Init_Boot.h"

int main()
{
	//VARIABLES AND INITIALIZATION
	sf::RenderWindow window;
	sf::Clock mainFPSClock;
	windowInit( window, 768, 1024, 60, false, false );
	sf::Vector2f windowSize(window.getSize().x, window.getSize().y);


	/////TEST SHAPE SHIT/////
		sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
		shape.setFillColor( sf::Color::Magenta );
		shape.setOrigin(shape.getGeometricCenter());
		shape.setPosition( windowSize / 2.f );

	//////////////////////////
	//START CLOCK B4 ENTER MAIN LOOP FOR FPS
	////////////////////////
	mainFPSClock.restart();
	while ( window.isOpen() )
	{
		//////EVENT HANDLING//////////
		/////////////////////////
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
			if ( event->is<sf::Event::KeyPressed>() && shape.getFillColor() == sf::Color::Magenta ) {
				shape.setFillColor( sf::Color::Yellow );
				break;
			}
			if ( event->is<sf::Event::KeyPressed>() && shape.getFillColor() == sf::Color::Yellow )
				shape.setFillColor( sf::Color::Magenta );
				break;
		}

		////FPS CONTROL/////////
		//////////////////////
			if (mainFPSClock.getElapsedTime().asMilliseconds() >= 1000) {

				/////MORE TEST SHAPE SHIT///////////
				//////////////////////////////////
				const sf::Angle angle1 = shape.getRotation();
				//shape.rotate(angle1 + sf::degrees(.0002f));
				shape.setRotation(angle1 + sf::degrees(.2f));

				/////////////////////////////
				///Window Functions///////
				/////////////////////////
				window.clear(sf::Color::Blue);
				window.draw( shape );
				window.display();
			}
	}
}