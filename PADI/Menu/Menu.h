#pragma once

#include "../InputManager.h"
#include "Menu.h"

class StateManager;

class Menu
{
public:
	Menu(StateManager& sm, sf::RenderWindow* window)
		: sm{ sm }, window{ window } {}
	virtual ~Menu() {}

	virtual void HandleEvents() = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Draw() = 0;

protected:
	StateManager& sm;
	sf::RenderWindow* window;
};