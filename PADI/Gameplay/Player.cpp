#include "Player.h"
#include "../InputManager.h"
#include "Map.h"

Player::Player(sf::Vector2f spawn)
	: Character(spawn)
{
	sprite.setTexture(*g_Res->getTextureByName("jojo"));
	sprite.setScale(
		(float) 40 / sprite.getTexture()->getSize().x,
		(float) 64 / sprite.getTexture()->getSize().y
	);
	sprite.setOrigin(
		sprite.getTexture()->getSize().x / 2,
		sprite.getTexture()->getSize().y / 2
	);

	MovementSpeed = 250.f;
	Health_Max = 5;
	Health_Current = Health_Max;
}

Player::~Player()
{

}

void Player::HandleEvents()
{
	direction = MovementInput();

	if (g_Input->isKeyPressed(sf::Keyboard::J))
	{
		this->bAttacking = true;
	}
	if (!g_Input->isKeyPressed(sf::Keyboard::J))
	{
		this->bAttacking = false;
	}
}

void Player::Update(const float& dt)
{
}

void Player::FixedUpdate(const float& dt)
{
	sprite.move(direction * MovementSpeed * dt);
	CheckBorders();
}

void Player::Draw(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Player::TakeDamage()
{
	Character::TakeDamage();
	g_Res->playSoundByName("ahh", g_Res->getSFXVolume(), false);
}

void Player::CheckBorders()
{
	if (sprite.getPosition().x < 0)
		sprite.setPosition(0, sprite.getPosition().y);
	if (sprite.getPosition().x > WIN_WIDTH)
		sprite.setPosition(WIN_WIDTH, sprite.getPosition().y);
	if (sprite.getPosition().y < 0)
		sprite.setPosition(sprite.getPosition().x, 0);
	if (sprite.getPosition().y > WIN_HEIGHT - 112)
		sprite.setPosition(sprite.getPosition().x, WIN_HEIGHT - 112);
}

sf::Vector2f Player::MovementInput()
{
	sf::Vector2f direction;
	if (g_Input->isKeyDown(sf::Keyboard::A))
	{
		direction += sf::Vector2f(-1, 0);
	}
	if (g_Input->isKeyDown(sf::Keyboard::D))
	{
		direction += sf::Vector2f(1, 0);
	}
	if (g_Input->isKeyDown(sf::Keyboard::W))
	{
		direction += sf::Vector2f(0, -1);
	}
	if (g_Input->isKeyDown(sf::Keyboard::S))
	{
		direction += sf::Vector2f(0, 1);
	}

	return direction;
}
