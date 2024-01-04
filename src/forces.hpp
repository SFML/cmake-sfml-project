#include "particle.hpp"
class Force {
    public:
        static void ApplyGravity(Particle& particle, float gravitationalconstant, float dt) {
            float gravityForce = gravitationalconstant * particle.getMass();
            particle.ApplyForce(0, gravityForce, dt);
        }
};