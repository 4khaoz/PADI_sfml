#include "Projectile.h"
#include "Enemy.h"
#include "Player.h"

Projectile::Projectile(sf::Vector2f spawn, sf::Vector2f direction, float speed, Actor& instigator) 
	: Actor(spawn), direction(direction), instigator(instigator)
{
	this->speed = speed;

	if (!texture.loadFromFile("..\\Resources\\projectile.png"))
	{
		return;
	}

	sprite.setTexture(texture);
	sprite.setScale(
		(float) 50 / sprite.getTexture()->getSize().x,
		(float) 50 / sprite.getTexture()->getSize().y
	);
	sprite.setOrigin(
		sprite.getTexture()->getSize().x / 2,
		sprite.getTexture()->getSize().y / 2
	);
}

Projectile::~Projectile()
{
}

void Projectile::HandleEvents()
{
	
}

void Projectile::Update(const float& dt)
{
	sprite.move(direction * dt * speed);
}

void Projectile::Draw(sf::RenderTarget& target)
{
	target.draw(sprite);
}

bool Projectile::checkCollision(Actor& other)
{
	if (dynamic_cast<Enemy*>(&instigator) && dynamic_cast<Player*>(&other))
	{
		if (this->getHitbox().intersects(other.getHitbox()))
		{
			std::cout << "Enemy hit smth" << std::endl;
			return true;
		}
	}

	if (dynamic_cast<Player*>(&instigator) && dynamic_cast<Enemy*>(&other))
	{
		if (this->getHitbox().intersects(other.getHitbox()))
		{
			std::cout << "Hit detected" << std::endl;
			return true;
		}
	}

	return false;
}
