#include "PhysicsWindow.h"
#include "Particle.h"
#include <iostream>

void PhysicsWindow::run() {
    window.create(sf::VideoMode(1600, 1000), "2D GRAVITY SIMULATOR");
    window.setFramerateLimit(60);


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i v = sf::Mouse::getPosition(window);
            fixedGravSources[0]->setGravityStrength(15000);
            fixedGravSources[0]->pos = sf::Vector2f(v.x, v.y);
        }
        else fixedGravSources[0]->setGravityStrength(0);

        updatePhysicsAll();
        window.clear();
        renderAll();
        window.display();
    }
}

void PhysicsWindow::renderAll() {
    for (int i = 0; i < fixedGravSources.size(); i++) {
        fixedGravSources[i]->render(window);
    }
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->render(window);
    }
}

void PhysicsWindow::updatePhysicsAll() {
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->updatePhysics(fixedGravSources);
        particles[i]->updatePhysics(particles);
    }
}

void PhysicsWindow::addFixedGravitySource(float px, float py, float strength, float rad) {
    fixedGravSources.push_back(new Particle(px, py, 0, 0, strength, rad));
}

void PhysicsWindow::addParticle(float px, float py, float vx, float vy, float strength, float rad) {
    particles.push_back(new Particle(px, py, vx, vy, strength, rad));
}

void PhysicsWindow::addParticleWithColor(float px, float py, float vx, float vy, float strength, float rad, sf::Color color) {
    Particle* p = new Particle(px, py, vx, vy, strength, rad);
    p->sprite.setFillColor(color);
    particles.push_back(p);
}