#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(sf::Vector2f spawn, int difficulty);
	~Enemy();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void Draw(sf::RenderTarget& target);

	virtual void TakeDamage();

private:
	sf::Clock atk_clock;
	sf::Clock hp_reg_clock;

	float fAttackTimer;
	float fHPRegTimer;
	float HP_Regeneration;
	bool bCanRegenerate;

	sf::Vector2f direction;

	void initDifficulty(int d);
	void Move(const float& dt);
	void Attack();
	void Regenerate();
};