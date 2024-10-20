#include "SceneRenderer.h"
#include "common/calc.h"
#include "pathing/Spline.h"
#include "pathing/Trajectory.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <utility>

void SceneRenderer::render(sf::RenderTarget* texture) {
    texture->clear();
    std::shared_ptr<Trajectory> trajectory = manager->getTrajectory();
    for (Spline& spline: trajectory->splines) {
        double start = spline.start.position.x();
        double end = spline.end.position.x();
        if (end < start) {
            std::swap(start, end);
        }
        
        for (double x = start; x <= end; x += 1) {
            drawPoint(texture, sf::Vector2f(x, getY(spline.coefficients, x)), 0.25, sf::Color::Green);
        }
        drawPoint(texture, sf::Vector2f(spline.start.position.x(), spline.start.position.y()), 0.5, sf::Color::Blue);
        drawPoint(texture, sf::Vector2f(spline.end.position.x(), spline.end.position.y()), 0.5, sf::Color::Blue);
    }
}

void SceneRenderer::drawPoint(sf::RenderTarget* target, const sf::Vector2f& pos, double radius, const sf::Color& color) {
    sf::CircleShape circle;
    circle.setOrigin(radius, radius);
    circle.setPosition(pos.x, -pos.y);
    circle.setFillColor(color);
    circle.setRadius(radius);
    target->draw(circle);
}