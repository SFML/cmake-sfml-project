#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib> // For rand()
#include <iostream>
#include <cmath>
#include "particle.hpp"
#include "forces.hpp"

//cmon work
const int cellWidth = 100;
const int cellHeight = 100;
std::vector<std::vector<std::vector<Particle*>>> grid;
std::vector<Particle> particles;
// Function to render a particle

// Function to render a wall
void RenderWall(sf::RenderWindow& window, const sf::RectangleShape& wall) {
    window.draw(wall);
}

bool isColliding(Particle& particle1, Particle& particle2) {
    float dist = sqrt(pow((particle1[0] - particle2[0]), 2) + pow((particle1[1] - particle2[1]),2));
    if (dist < particle1.getRadius() + particle2.getRadius()) return true;
    else return false;
}

void checkAndBounceOffWalls(Particle& particle, float windowWidth, float windowHeight) {
    float radius = particle.getRadius();  // Particle radius
    float restitution = 0.9f; // Coefficient of restitution (example value)

    // Check for collision with left and right walls
    if (particle[0] - radius < 0) {
        particle.setVelocityX(-particle.getVelocityX() * restitution);  // Apply restitution to horizontal velocity
        particle[0] = radius;  // Adjust position to be just outside the wall
    } else if (particle[0] + radius > windowWidth) {
        particle.setVelocityX(-particle.getVelocityX() * restitution);  // Apply restitution to horizontal velocity
        particle[0] = windowWidth - radius;  // Adjust position to be just outside the wall
    }

    // Check for collision with top and bottom walls
    if (particle[1] - radius < 0) {
        particle.setVelocityY( -particle.getVelocityY() * restitution);  // Apply restitution to vertical velocity
        particle[1] = radius;  // Adjust position to be just outside the wall
    } else if (particle[1] + radius > windowHeight) {
        particle.setVelocityY( -particle.getVelocityY() * restitution);  // Apply restitution to vertical velocity
        particle[1] = windowHeight - radius;  // Adjust position to be just outside the wall
    }
}


void resolveCollision(Particle& particle1, Particle& particle2) {
    // Calculate the difference in velocities and positions
    float restitution = 0.9f;
    float dvx = particle1.getVelocityX() - particle2.getVelocityX();
    float dvy = particle1.getVelocityY() - particle2.getVelocityY();
    float dx = particle1[0] - particle2[0];
    float dy = particle1[1] - particle2[1];

        // Calculate the overlap distance
    float overlap = particle1.getRadius() + particle2.getRadius() - sqrt(pow(dx, 2) + pow(dy, 2)); // 20.0f should be the sum of radii of the two particles
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
    particle1.setVelocityX(particle1.getVelocityX() - factor * particle2.getMass() * dotProduct * dx);
    particle1.setVelocityY(particle1.getVelocityY() - factor * particle2.getMass() * dotProduct * dy);
    particle2.setVelocityX(particle2.getVelocityX() + factor * particle1.getMass() * dotProduct * dx);
    particle2.setVelocityY(particle2.getVelocityY() + factor * particle1.getMass() * dotProduct * dy);
}

bool isOverlapping(const Particle& newParticle, const std::vector<Particle>& particles) {
    for (const auto& particle : particles) {
        float dist = sqrt(pow(newParticle[0] - particle[0], 2) + pow(newParticle[1] - particle[1], 2));
        if (dist < particle.getRadius() + newParticle.getRadius()) {  // Assuming each particle has a diameter of 100
            return true;
        }
    }
    return false;
}

void updateGrid() {
    // Clear the grid
    for (auto &column: grid) {
        for (auto &cell: column) {
            cell.clear();
        }
    }

    // Assign particles to the grid cells
    for (Particle& particle : particles) {
        int gridX = particle.getX() / cellWidth;
        int gridY = particle.getY() / cellHeight;
        if(gridX >= 0 && gridX < grid.size() && gridY >= 0 && gridY < grid[gridX].size()) {
            grid[gridX][gridY].push_back(&particle);
        }
    }
}




int main() {
    srand(static_cast<unsigned int>(time(0)));
    auto window = sf::RenderWindow{{1920u, 1080u}, "CMake SFML Project"};
    window.setFramerateLimit(144);

    // Initialize the grid based on the window size and cell dimensions
    int gridRows = 1080 / cellHeight;
    int gridCols = 1920 / cellWidth;
    grid.resize(gridCols, std::vector<std::vector<Particle*>>(gridRows));

    // Create a vector of particles
    // std::vector<Particle> particles;
    for (int i = 0; i < 1000; ++i) {
    bool positionFound = false;
    Particle newParticle;

    while (!positionFound) {
        float x = static_cast<float>(rand() % 1920);
        float y = static_cast<float>(rand() % 1080);
        float vx = static_cast<float>(rand() % 100) / 10.0f - 50.0f;
        float vy = static_cast<float>(rand() % 100) / 10.0f - 50.0f;
        newParticle = Particle(x, y, vx, vy, 1.0f, 3.0f);

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

        updateGrid();

        // Collision detection and resolution
        for (size_t x = 0; x < grid.size(); ++x) {
            for (size_t y = 0; y < grid[x].size(); ++y) {
                for (Particle* particle : grid[x][y]) {
                    // Check for collisions with particles in the same cell
                    for (Particle* other : grid[x][y]) {
                        if (particle != other && isColliding(*particle, *other)) {
                            resolveCollision(*particle, *other);
                        }
                    }

                    // Check for collisions with particles in adjacent cells
                    for (int dx = -1; dx <= 1; ++dx) {
                        for (int dy = -1; dy <= 1; ++dy) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[nx].size()) {
                                for (Particle* neighbor : grid[nx][ny]) {
                                    if (particle != neighbor && isColliding(*particle, *neighbor)) {
                                        resolveCollision(*particle, *neighbor);
                                    }
                                }
                            }
                        }
                    }
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
