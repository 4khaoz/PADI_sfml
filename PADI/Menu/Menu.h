#pragma once

#include "../InputManager.h"
#include "Menu.h"

class StateManager;

class Menu
{
public:
	Menu(StateManager& sm, sf::RenderWindow* window)
		: sm{ sm }, window{ window }, bQuit(false) { }
	virtual ~Menu() {}

	virtual void HandleEvents() = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Draw() = 0;

	virtual void updateMousePosition()
	{
		mousePosScreen = sf::Mouse::getPosition();
		mousePosWindow = sf::Mouse::getPosition(*window);
		mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	}

	const bool& getQuit() const { return bQuit; }

protected:
	StateManager& sm;
	sf::RenderWindow* window;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	bool bQuit;
};