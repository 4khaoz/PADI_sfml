#pragma once
#include "Menu/StateManager.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow* window;
	sf::VideoMode vidmode;
	sf::Event e;
	sf::Clock clock;

	StateManager* sm;
	float dt;

	void HandleEvents();
	void SetDeltaTime();
};