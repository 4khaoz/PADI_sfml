#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(sf::Vector2f spawn, GameInstance& ref, int difficulty);
	~Enemy();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void FixedUpdate(const float& dt);
	virtual void Draw(sf::RenderTarget& target);

	virtual void TakeDamage();

private:
	sf::Clock atk_clock;
	sf::Clock hp_reg_clock;

	float fAttackTimer;
	float fHPRegTimer;
	float HP_Regeneration;
	bool bCanRegenerate;
	bool bAttackFromAbove;

	sf::Vector2f direction;
	float rotator;
	float rotationspeed;

	void initDifficulty(int d);
	void Move(const float& dt);
	void Attack();
	void Regenerate();
	void SimpleRotatorAnimation(const float& dt);
};