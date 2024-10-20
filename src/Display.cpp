#include "Display.h"
#include "IMenuItem.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cassert>
#include <imgui-SFML.h>
#include <memory>

Display::Display(int width, int height, const std::shared_ptr<SceneRenderer>& renderer) {
    this->renderer = renderer;
    window.create(sf::VideoMode(width, height), "RoboOpVisualizer");
    scene.create(width, height);
    double viewWidth = 72;
    scene.setView(sf::View(sf::FloatRect(-viewWidth/2, -viewWidth/2, viewWidth, viewWidth)));
    window.setFramerateLimit(144);
    assert(ImGui::SFML::Init(window));
}

bool Display::update() {
    sf::Clock clock;
    if (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                shutdown();
                return false;
            }
        }

        sf::Vector2i vec{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right), sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)};
        if (vec.x != 0 || vec.y != 0) {
            sf::View newView = scene.getView();
            double time = clock.restart().asSeconds();
            double speed = 100;
            newView.move(-vec.x * time * speed,  -vec.y * time * speed);
            scene.setView(newView);
            updateScene();
        }

        ImGui::SFML::Update(window, clock.restart());

        window.clear();
        scene.display();
        window.draw(sf::Sprite{scene.getTexture()});

        for (const std::shared_ptr<IMenuItem>& item: menus) {
            item->render();
        }

        ImGui::SFML::Render(window);

        window.display();
    }
    return true;
}

void Display::shutdown() {
    window.close();
    ImGui::SFML::Shutdown();
}

void Display::updateScene() {
    renderer->render(&scene);
}