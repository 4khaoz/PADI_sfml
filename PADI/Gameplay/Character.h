#pragma once
#include "Actor.h"

class Map;

class Character : public Actor
{
public:
	Character(sf::Vector2f spawn);
	~Character();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void Draw(sf::RenderTarget& target);

	virtual bool isCharacterAttacking() { return bAttacking; }

	void TakeDamage();

	float GetHealth() { return Health_Current; }
	float GetHealthMax() { return Health_Max; }
	float GetHealthPercentage() { return Health_Current / Health_Max; }

	bool isAlive() { return bAlive; }

protected:
	bool bAttacking;
	bool bAlive;
	Map& map;
	sf::Image img;

	float Health_Current;
	float Health_Max;
};