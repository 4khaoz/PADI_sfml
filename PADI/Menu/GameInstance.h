#pragma once
#include "Menu.h"
#include "../Gameplay/Player.h"
#include "../Gameplay/Map.h"
#include "../UserInterface/ProgressBar.h"
#include "../UserInterface/Button.h"

enum class GameState {
	PLAYING,
	VICTORY,
	DEFEAT
};


class GameInstance : public Menu
{
public:
	GameInstance(StateManager& sm, sf::RenderWindow* window, int difficulty);
	~GameInstance();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void FixedUpdate(const float& dt);
	virtual void Draw();

private:
	Map map;
	sf::View view;
	GameState gs;
	bool bPlaying;
	
	// Actors
	Player* player;
	Enemy* enemy;
	std::vector<Projectile*> projectiles;

	void initUI();
	void UpdateProjectiles(const float& dt);
	void CheckGameState();

	// GUI
	ProgressBar* enemy_HPBar;
	ProgressBar* player_HPBar;
	Button* endButton;
};