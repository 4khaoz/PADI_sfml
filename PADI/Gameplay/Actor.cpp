#include "Actor.h"

Actor::Actor(sf::Vector2f spawn)
{
	sprite.setPosition(spawn);
}

Actor::~Actor()
{
}

bool Actor::checkCollision(Actor& other)
{
	if (this->sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds()))
	{
		std::cout << "Collision detected" << std::endl;
		return true;
	}

	return false;
}
