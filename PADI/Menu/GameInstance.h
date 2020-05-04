#pragma once
#include "Menu.h"
#include "../Gameplay/Player.h"
#include "../Gameplay/Map.h"
#include "../UserInterface/ProgressBar.h"

class GameInstance : public Menu
{
public:
	GameInstance(StateManager& sm, sf::RenderWindow* window);
	~GameInstance();

	void HandleEvents();
	void Update(const float& dt);
	void Draw();

private:
	Map map;
	sf::View view;
	
	// Actors
	Player* player;
	Enemy* enemy;
	std::vector<Projectile*> projectiles;

	// GUI
	ProgressBar* enemy_HPBar;
	ProgressBar* player_HPBar;
};