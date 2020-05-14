#pragma once
#include "Actor.h"

class Projectile : public Actor
{
public:
	Projectile(
		sf::Vector2f spawn, 
		sf::Vector2f direction,
		float speed,
		Actor& instigator
	);
	~Projectile();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void FixedUpdate(const float& dt);
	virtual void Draw(sf::RenderTarget& target);

	virtual bool checkCollision(Actor& other);

private:
	Actor& instigator;
	sf::Vector2f direction;
	float speed;
};