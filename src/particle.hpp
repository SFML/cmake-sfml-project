#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <stdexcept>
#include <SFML/Graphics.hpp>

class Particle {
private:
    float x, y;
    float vx, vy;
    float mass;
    float radius;

public:
    // Default constructor
    Particle() : x(0), y(0), vx(0), vy(0), mass(1), radius(10.0f) {}

    // Parameterized constructor
    Particle(float x, float y, int vx, int vy, float mass, float radius)
        : x(x), y(y), vx(vx), vy(vy), mass(mass), radius(radius) {}

    void ApplyForce(float xforce, float yforce, float dt){
        float xacceleration = xforce / mass;
        float yacceleration = yforce / mass;
        vx += xacceleration * dt;
        vy += yacceleration * dt;
    }

    void Update(float dt){
        x += vx * dt;
        y += vy * dt;
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

    float& getvx(){
        return vx;
    }
    float& getvy(){
        return vy;
    }

    const float& getradius() const{
        return radius;
    }

    void Render(sf::RenderWindow& window) const {
            sf::CircleShape shape(radius); // example radius
            shape.setFillColor(sf::Color::White);
            shape.setPosition(x, y);
            window.draw(shape);
        }

      
};
#endif // PARTICLE_HPP