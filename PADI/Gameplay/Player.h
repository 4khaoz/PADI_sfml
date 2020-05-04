#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player(sf::Vector2f spawn);
	~Player();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void Draw(sf::RenderTarget& target);

private:
	void CheckBorders();

	sf::Vector2f direction;
	sf::Vector2f MovementInput();

	float MovementSpeed;

	unsigned int Strength = 5;
	unsigned int Agility = 5;
	unsigned int Intelligence = 5;
	unsigned int Vitality = 5;
};