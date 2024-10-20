#pragma once

#include "IMenuItem.h"
#include "SceneRenderer.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>

class Display {
private:
    sf::RenderTexture scene;
    sf::RenderWindow window;
    sf::Clock clock;
    std::shared_ptr<SceneRenderer> renderer;
public:
    std::vector<std::shared_ptr<IMenuItem>> menus;
    Display(int width, int height, const std::shared_ptr<SceneRenderer>& renderer);
    bool update();
    void shutdown();
    void updateScene();
};