#include "Player.h"
#include "../InputManager.h"
#include "Map.h"

Player::Player(sf::Vector2f spawn)
	: Character(spawn)
{
	if (!img.loadFromFile("..\\Resources\\placeholder.png"))
		return;

	// Transparent Sprite Background
	img.createMaskFromColor(sf::Color::White);

	if (!texture.loadFromImage(img))
		return;

	sprite.setTexture(texture);
	sprite.setScale(
		(float) 64 / texture.getSize().x,
		(float) 64 / texture.getSize().y
	);
	//sprite.setPosition(spawn);
	sprite.setOrigin(
		sprite.getTexture()->getSize().x / 2,
		sprite.getTexture()->getSize().y / 2
	);

	sound.setBuffer(*g_Res->getSoundByName("ahh"));
	sound.setVolume(100);

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
		std::cout << "J" << std::endl;
		this->bAttacking = true;
	}
	if (!g_Input->isKeyPressed(sf::Keyboard::J))
	{
		this->bAttacking = false;
	}
}

void Player::Update(const float& dt)
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
	sound.play();
	if (sound.getStatus() == sf::Sound::Status::Playing)
		std::cout << "player sound" << std::endl;
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
	if (g_Input->isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "X: " << sprite.getPosition().x << std::endl;
		std::cout << "Y: " << sprite.getPosition().y << std::endl;
	}

	return direction;
}
