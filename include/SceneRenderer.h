#pragma once

#include "TrajectoryManager.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

class SceneRenderer {
private:
    std::shared_ptr<TrajectoryManager> manager;
public:
    SceneRenderer(const std::shared_ptr<TrajectoryManager>& manager): manager{manager}{}
    void render(sf::RenderTarget* texture);
    void drawPoint(sf::RenderTarget* target, const sf::Vector2f& pos, double radius, const sf::Color& color);
};