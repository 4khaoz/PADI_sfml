#include "Character.h"

Character::Character(sf::Vector2f spawn, GameInstance& ref)
	: Actor(spawn), gameinstanceref(ref)//, map(map)
{
	bAlive = true;
}

Character::~Character()
{
}

void Character::HandleEvents()
{
}

void Character::Update(const float& dt)
{
	
}

void Character::FixedUpdate(const float& dt)
{
}

void Character::Draw(sf::RenderTarget& target)
{
}

void Character::TakeDamage()
{
	Health_Current = fClamp(Health_Current-1, 0, Health_Max);
	if (Health_Current <= 0)
	{
		bAlive = false;
	}
}
