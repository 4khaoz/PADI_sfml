#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(sf::Vector2f spawn);
	~Enemy();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void Draw(sf::RenderTarget& target);

private:
	sf::Clock clock;
	sf::Vector2f direction;
};