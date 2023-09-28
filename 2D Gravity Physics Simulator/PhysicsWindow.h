#ifndef PHYSICSWINDOW_H
#define PHYSICSWINDOW_H

#include <SFML/Graphics.hpp>
#include "Particle.h"
#include <vector>

class PhysicsWindow {
public:
	void run();
	void addFixedGravitySource(float px, float py, float strength, float rad);
	void addParticle(float px, float py, float vx, float vy, float strength, float rad);
	void addParticleWithColor(float px, float py, float vx, float vy, float strength, float rad, sf::Color color);
	void renderAll();
	void updatePhysicsAll();
	PhysicsWindow() { fixedGravSources.push_back(new Particle()); }

private:
	sf::RenderWindow window;
	std::vector<Particle*> fixedGravSources;
	std::vector<Particle*> particles;
};



#endif