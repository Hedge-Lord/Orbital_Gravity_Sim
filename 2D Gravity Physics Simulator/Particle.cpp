#include "Particle.h"
#include <cmath>

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity) : pos(position), vel(velocity) {
	sprite.setPosition(position);
	sprite.setFillColor(sf::Color::White);
	sprite.setRadius(4);
}

void Particle::updatePhysics(GravitySource* gp) {
	float dx = gp->pos.x - pos.x;
	float dy = gp->pos.y - pos.y;
	float dist = sqrt(dx * dx + dy * dy);
	float inverse_dist = 1.f / dist;
	float gravStrength = gp->getGravityStrength() * inverse_dist * inverse_dist;
	vel.x += (gravStrength * dx * inverse_dist);
	vel.y += (gravStrength * dy * inverse_dist);

	pos.x += vel.x;
	pos.y += vel.y;
}

void Particle::render(sf::RenderWindow& win) {
	sprite.setPosition(pos);
	win.draw(sprite);
}
