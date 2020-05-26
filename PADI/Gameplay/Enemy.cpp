#include "Enemy.h"
#include "../Menu/GameInstance.h"

Enemy::Enemy(sf::Vector2f spawn, GameInstance& ref, int difficulty)
	: Character(spawn, ref)
{
	initDifficulty(difficulty);

	sprite.setScale(
		(float)300 / sprite.getTexture()->getSize().x,
		(float)240 / sprite.getTexture()->getSize().y
	);
	sprite.setOrigin(
		sprite.getTexture()->getSize().x / 2,
		sprite.getTexture()->getSize().y / 2
	);

	direction = sf::Vector2f(0, 1);
	rotator = 1.f;
	rotationspeed = 60.f;

	srand((unsigned int)time(NULL));

	fAttackTimer = float(rand()) / float((RAND_MAX) * 5) + 1.f;
}

Enemy::~Enemy()
{
}

void Enemy::HandleEvents()
{
}

void Enemy::Update(const float& dt)
{
	Attack();

	if (bCanRegenerate)
		Regenerate();
}

void Enemy::FixedUpdate(const float& dt)
{
	Move(dt);
	SimpleRotatorAnimation(dt);
}

void Enemy::Draw(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Enemy::TakeDamage()
{
	Character::TakeDamage();

	g_Res->playSoundByName("clap", g_Res->getSFXVolume(), false);
}

void Enemy::initDifficulty(int d)
{
	switch (d)
	{
	case 0:
		sprite.setTexture(*g_Res->getTextureByName("troll"));
		Health_Max = 250;
		bCanRegenerate = false; 
		bAttackFromAbove = false;
		break;
	case 1:
		sprite.setTexture(*g_Res->getTextureByName("knuckles"));
		Health_Max = 350;
		bCanRegenerate = true;
		bAttackFromAbove = false;
		fHPRegTimer = 5.f;
		HP_Regeneration = 2.f;
		break;
	case 2:
		sprite.setTexture(*g_Res->getTextureByName("sponge"));
		Health_Max = 500;
		bCanRegenerate = true;
		bAttackFromAbove = true;
		fHPRegTimer = 5.f;
		HP_Regeneration = 5.f;
		break;
	default:
		Health_Max = 250;
	}
	Health_Current = Health_Max;
}

void Enemy::Move(const float& dt)
{
	if (sprite.getPosition().y + 100 > WIN_HEIGHT)
	{
		direction = sf::Vector2f(0, -1);
	}

	if (sprite.getPosition().y < 0)
	{
		direction = sf::Vector2f(0, 1);
	}

	sprite.move(direction * 150.f * dt);
}

void Enemy::Attack()
{
	if (atk_clock.getElapsedTime().asSeconds() > fAttackTimer)
	{
		gameinstanceref.SpawnProjectile(getPosition(), sf::Vector2f(-1, 0), 325.f, dynamic_cast<Actor&>(*this), "kappa");
		if (bAttackFromAbove)
		{
			for (int i = 0; i < 3; ++i)
			{
				float rnd = ((float)rand()) / (float)RAND_MAX * getPosition().x;
				gameinstanceref.SpawnProjectile(sf::Vector2f(rnd, 0), sf::Vector2f(0, 1), 325.f, dynamic_cast<Actor&>(*this), "ayaya");
			}
		}

		fAttackTimer = float(rand()) / float((RAND_MAX) * 5) + 1.f;
		atk_clock.restart();
	}
}

void Enemy::Regenerate()
{
	if (hp_reg_clock.getElapsedTime().asSeconds() > fHPRegTimer)
	{
		Health_Current = fClamp(Health_Current + HP_Regeneration, Health_Current, Health_Max);
		hp_reg_clock.restart();
	}
}

void Enemy::SimpleRotatorAnimation(const float& dt)
{
	if (sprite.getRotation() > 15.f && rotator == 1.f)
	{
		rotator = -1.f;
	} 
	else if (sprite.getRotation() > 330.f && rotator == -1.f)
	{
		rotator = 1.f;
	}

	sprite.rotate(rotator * rotationspeed * dt);
}
