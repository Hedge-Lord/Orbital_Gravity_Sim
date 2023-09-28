#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

class Particle {
public:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::CircleShape sprite;
	float getGravityStrength() { return gravityStrength; }

	void setGravityStrength(float strength) { gravityStrength = strength; }

	void updatePhysics(std::vector<Particle*>& gravSources) {
		Particle* gp;
		for (int i = 0; i < gravSources.size(); i++) {
			gp = gravSources[i];
			if (this == gp) continue;
			if (!gp->getGravityStrength()) continue;
			float dx = gp->pos.x - pos.x;
			float dy = gp->pos.y - pos.y;
			float dist = sqrt(dx * dx + dy * dy);
			if (dist < 25) dist = 25;
			float inverse_dist = 1.f / dist;
			float gravStrength = gp->getGravityStrength() * inverse_dist * inverse_dist;

			vel.x += (gravStrength * dx * inverse_dist);
			vel.y += (gravStrength * dy * inverse_dist);
		}
		pos.x += vel.x;
		pos.y += vel.y;
		if (pos.x > 1600 || pos.x < 0 || pos.y < 0 || pos.y > 1000) {

			vel = -vel;
		}

	}

	Particle() {}

	Particle(float pos_x, float pos_y, float vel_x, float vel_y, float gravStrength, float rad) 
		: pos(sf::Vector2f(pos_x, pos_y)), vel(sf::Vector2f(vel_x, vel_y)), gravityStrength(gravStrength) {
		sprite.setPosition(this->pos);
		sprite.setFillColor(sf::Color::White);
		sprite.setRadius(rad);
	}

	void render(sf::RenderWindow& win) {
		sprite.setPosition(pos);
		win.draw(sprite);
	}

private:
	float gravityStrength = 0;
};

#endif
