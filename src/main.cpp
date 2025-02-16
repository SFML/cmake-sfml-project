#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        //sf::Texture texture("1162.jpg", false, sf::IntRect({10, 10}, {32, 32})); // Throws sf::Exception if an error occurs
        //sf::Texture texture("1162.jpg");
        //sf::Sprite sprite(texture);
        //window.draw(sprite);
        sf::CircleShape shape(50.f);
        shape.setFillColor(sf::Color(100, 250, 50));
        window.draw(shape);
        window.display();
    }
}
