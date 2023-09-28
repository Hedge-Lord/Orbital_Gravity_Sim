#include "PhysicsWindow.h"
#include <random>

int main()
{
    PhysicsWindow physics;
    physics.addFixedGravitySource(500, 500, 7000, 15);
    physics.addFixedGravitySource(1200, 500, 7000, 15);
    int num = 500;
    for (int i = 0; i < num; i++) {
        physics.addParticleWithColor(600, 700, 4, (0.2f + (0.1f / num * i)), 0, 10, sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
    }
    
    physics.run();

    return 0;
}