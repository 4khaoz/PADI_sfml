#pragma once
#include "../global.h"
#include "../ResourceManager.h"

class Actor
{
public:
	Actor(sf::Vector2f spawn);
	~Actor();

	virtual void HandleEvents() = 0;
	virtual void Update(const float& dt) = 0;
	virtual void FixedUpdate(const float& dt) = 0;
	virtual void Draw(sf::RenderTarget& target) = 0;

	virtual bool checkCollision(Actor& other);

	virtual sf::Vector2f getPosition() { return sprite.getPosition(); }

	virtual sf::FloatRect getHitbox() { return sprite.getGlobalBounds(); }

protected:
	sf::Sprite sprite;
};