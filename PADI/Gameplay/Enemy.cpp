#include "Enemy.h"

Enemy::Enemy(sf::Vector2f spawn, int difficulty)
	: Character(spawn)
{
	initDifficulty(difficulty);

	if (!img.loadFromFile("../Resources/trollface.png"))
		return;

	img.createMaskFromColor(sf::Color::White);
	texture.loadFromImage(img);
	sprite.setTexture(texture);

	sprite.setScale(
		(float)300 / texture.getSize().x,
		(float)300 / texture.getSize().y
	);
	sprite.setOrigin(
		sprite.getTexture()->getSize().x / 2,
		sprite.getTexture()->getSize().y / 2
	);

	sound.setBuffer(*g_Res->getSoundByName("clap"));
	sound.setVolume(100);

	direction = sf::Vector2f(0, 1);

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
	Move(dt);

	Attack();

	if (bCanRegenerate)
		Regenerate();
}

void Enemy::Draw(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Enemy::TakeDamage()
{
	Character::TakeDamage();

	sound.play();
}

void Enemy::initDifficulty(int d)
{
	switch (d)
	{
	case 0:
		Health_Max = 250;
		bCanRegenerate = false;
		break;
	case 1:
		Health_Max = 350;
		bCanRegenerate = true;
		fHPRegTimer = 5.f;
		HP_Regeneration = 2.f;
		break;
	case 2:
		Health_Max = 500;
		bCanRegenerate = true;
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
	if (bAttacking)
	{
		bAttacking = false;
	}
	if (!bAttacking && atk_clock.getElapsedTime().asSeconds() > fAttackTimer)
	{
		fAttackTimer = float(rand()) / float((RAND_MAX) * 5) + 1.f;
		bAttacking = true;
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
