#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib> // For rand()
#include <iostream>
#include <cmath>
#include "particle.hpp"
#include "forces.hpp"

// Function to render a particle

// Function to render a wall
void RenderWall(sf::RenderWindow& window, const sf::RectangleShape& wall) {
    window.draw(wall);
}

bool isColliding(Particle& particle1, Particle& particle2) {
    float dist = sqrt(pow((particle1[0] - particle2[0]), 2) + pow((particle1[1] - particle2[1]),2));
    if (dist < particle1.getradius() + particle2.getradius()) return true;
    else return false;
}

void checkAndBounceOffWalls(Particle& particle, float windowWidth, float windowHeight) {
    float radius = particle.getradius();  // Particle radius
    float restitution = 0.99f; // Coefficient of restitution (example value)

    // Check for collision with left and right walls
    if (particle[0] - radius < 0) {
        particle.getvx() = -particle.getvx() * restitution;  // Apply restitution to horizontal velocity
        particle[0] = radius;  // Adjust position to be just outside the wall
    } else if (particle[0] + radius > windowWidth) {
        particle.getvx() = -particle.getvx() * restitution;  // Apply restitution to horizontal velocity
        particle[0] = windowWidth - radius;  // Adjust position to be just outside the wall
    }

    // Check for collision with top and bottom walls
    if (particle[1] - radius < 0) {
        particle.getvy() = -particle.getvy() * restitution;  // Apply restitution to vertical velocity
        particle[1] = radius;  // Adjust position to be just outside the wall
    } else if (particle[1] + radius > windowHeight) {
        particle.getvy() = -particle.getvy() * restitution;  // Apply restitution to vertical velocity
        particle[1] = windowHeight - radius;  // Adjust position to be just outside the wall
    }
}


void resolveCollision(Particle& particle1, Particle& particle2) {
    // Calculate the difference in velocities and positions
    float restitution = 0.85f;
    float dvx = particle1.getvx() - particle2.getvx();
    float dvy = particle1.getvy() - particle2.getvy();
    float dx = particle1[0] - particle2[0];
    float dy = particle1[1] - particle2[1];

        // Calculate the overlap distance
    float overlap = particle1.getradius() + particle2.getradius() - sqrt(pow(dx, 2) + pow(dy, 2)); // 20.0f should be the sum of radii of the two particles
    if (overlap > 0) {
        // Move each particle away by half the overlap distance
        float overlapX = overlap * dx / (2 * sqrt(pow(dx, 2) + pow(dy, 2)));
        float overlapY = overlap * dy / (2 * sqrt(pow(dx, 2) + pow(dy, 2)));

        particle1[0] += overlapX;
        particle1[1] += overlapY;
        particle2[0] -= overlapX;
        particle2[1] -= overlapY;
    }


    // Calculate the factor for the velocity change (assuming equal mass)
    
    float factor = 2.0 / (particle1.getMass() + particle2.getMass());
    float dotProduct = (dvx * dx + dvy * dy) / (pow(dx, 2) + pow(dy, 2));
    dotProduct *= restitution;
    // Calculate new velocities
    particle1.getvx() -= factor * particle2.getMass() * dotProduct * dx;
    particle1.getvy() -= factor * particle2.getMass() * dotProduct * dy;
    particle2.getvx() += factor * particle1.getMass() * dotProduct * dx;
    particle2.getvy() += factor * particle1.getMass() * dotProduct * dy;
}

bool isOverlapping(const Particle& newParticle, const std::vector<Particle>& particles) {
    for (const auto& particle : particles) {
        float dist = sqrt(pow(newParticle[0] - particle[0], 2) + pow(newParticle[1] - particle[1], 2));
        if (dist < particle.getradius() + newParticle.getradius()) {  // Assuming each particle has a diameter of 100
            return true;
        }
    }
    return false;
}



int main() {
    auto window = sf::RenderWindow{{1920u, 1080u}, "CMake SFML Project"};
    window.setFramerateLimit(144);

    // Create a vector of particles
    std::vector<Particle> particles;
    for (int i = 0; i < 100; ++i) {
    bool positionFound = false;
    Particle newParticle;

    while (!positionFound) {
        float x = static_cast<float>(rand() % 1920);
        float y = static_cast<float>(rand() % 1080);
        float dx = static_cast<float>(rand() % 100) / 10.0f - 50.0f;
        float dy = static_cast<float>(rand() % 100) / 10.0f - 50.0f;
        newParticle = Particle(x, y, dx, dy, 1.0f, 10.0f);

        if (!isOverlapping(newParticle, particles)) {
            positionFound = true;
        }
    }

    particles.emplace_back(newParticle);
}

    // Define and initialize a wall
    sf::RectangleShape wall(sf::Vector2f(200, 200)); // Width and height of the wall
    wall.setPosition(1920, 1080); // Position of the wall
    wall.setFillColor(sf::Color::Red); // Color of the wall    

    float dt = 1.0f / 60.0f; // Assuming 60 updates per second

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update particles
        for (Particle& particle : particles) {
            Force::ApplyGravity(particle, 9.8f, dt);
            checkAndBounceOffWalls(particle, 800.0f, 800.0f);
            particle.Update(dt);
        }

        // Collision detection and resolution
        for (size_t i = 0; i < particles.size(); ++i) {
            for (size_t j = i + 1; j < particles.size(); ++j) {
                if (isColliding(particles[i], particles[j])) {
                    resolveCollision(particles[i], particles[j]);
                }
            }
        }

        // Render particles
        window.clear();
        for (const Particle& particle : particles) {
            particle.Render(window);
        }

        // Render wall
        RenderWall(window, wall);


        window.display();
    }
}
