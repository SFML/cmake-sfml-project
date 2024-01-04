#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <stdexcept>
#include <SFML/Graphics.hpp>

class Particle {
private:
    float x, y;
    float dx, dy;
    float mass;

public:
    // Default constructor
    Particle() : x(0), y(0), dx(0), dy(0), mass(1) {}

    // Parameterized constructor
    Particle(float x, float y, int dx, int dy, float mass)
        : x(x), y(y), dx(dx), dy(dy), mass(mass) {}

    void ApplyForce(float xforce, float yforce, float dt){
        float xacceleration = xforce / mass;
        float yacceleration = yforce / mass;
        dx += xacceleration * dt;
        dy += yacceleration * dt;
    }

    void Update(float dt){
        x += dx * dt;
        y += dy * dt;
    }

    float& operator[](int i){
        if (i == 0){
            return x;
        }
        else if (i == 1){
            return y;
        }
        else {
            // Throwing a runtime error
            throw std::runtime_error("Invalid index for Particle");
        }
    }

    const float& operator[](int i) const{
        if (i == 0){
            return x;
        }
        else if (i == 1){
            return y;
        }
        else {
            // Throwing a runtime error
            throw std::runtime_error("Invalid index for Particle");
        }
    }

    const float& getMass(){
        return mass;
    }

    float& getdx(){
        return dx;
    }
    float& getdy(){
        return dy;
    }

    void Render(sf::RenderWindow& window) const {
            sf::CircleShape shape(5); // example radius
            shape.setFillColor(sf::Color::White);
            shape.setPosition(x, y);
            window.draw(shape);
        }

      
};
#endif // PARTICLE_HPP