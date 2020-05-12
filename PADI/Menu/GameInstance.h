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

	void HandleEvents();
	void Update(const float& dt);
	void Draw();

private:
	Map map;
	sf::View view;
	GameState gs;
	sf::Sound endsound;
	sf::Sound bgm;
	bool bPlaying;
	
	// Actors
	Player* player;
	Enemy* enemy;
	std::vector<Projectile*> projectiles;

	void initUI();
	void UpdateProjectiles(const float& dt);

	// GUI
	ProgressBar* enemy_HPBar;
	ProgressBar* player_HPBar;
	Button* endButton;
};