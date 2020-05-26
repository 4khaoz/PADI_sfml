#pragma once
#include "Actor.h"

class GameInstance;

class Character : public Actor
{
public:
	Character(sf::Vector2f spawn, GameInstance& ref);
	~Character();
	
	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void FixedUpdate(const float& dt);
	virtual void Draw(sf::RenderTarget& target);

	virtual void TakeDamage();

	float GetHealth() { return Health_Current; }
	float GetHealthMax() { return Health_Max; }
	float GetHealthPercentage() { return Health_Current / Health_Max; }

	bool isAlive() { return bAlive; }

protected:
	bool bAlive;

	float Health_Current;
	float Health_Max;

	GameInstance& gameinstanceref;
};