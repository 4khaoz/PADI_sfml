#include "Enemy.h"

Enemy::Enemy(sf::Vector2f spawn)
	: Character(spawn)
{
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

	direction = sf::Vector2f(0, 1);

	Health_Max = 100;
	Health_Current = Health_Max;

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
	if (sprite.getPosition().y + 100 > WIN_HEIGHT)
	{
		direction = sf::Vector2f(0, -1);
	}

	if (sprite.getPosition().y < 0)
	{
		direction = sf::Vector2f(0, 1);
	}

	sprite.move(direction * 150.f * dt);

	if (bAttacking)
	{
		bAttacking = false;
	}
	if (!bAttacking && clock.getElapsedTime().asSeconds() > fAttackTimer)
	{
		fAttackTimer = float(rand()) / float((RAND_MAX) * 5) + 1.f;
		bAttacking = true;
		clock.restart();
	}
}

void Enemy::Draw(sf::RenderTarget& target)
{
	target.draw(sprite);
}
