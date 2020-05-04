#include "Character.h"

Character::Character(sf::Vector2f spawn)
	: Actor(spawn), map(map)
{
	bAttacking = false;
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

void Character::Draw(sf::RenderTarget& target)
{
}

void Character::TakeDamage()
{
	Health_Current = fClamp(Health_Current-1, 0, Health_Max);
}
