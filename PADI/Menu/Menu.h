#pragma once

#include "../InputManager.h"
#include "Menu.h"

class StateManager;

class Menu
{
public:
	Menu(StateManager& sm, sf::RenderWindow* window)
		: sm{ sm }, window{ window }, bQuit(false), kt(0.f) { }
	virtual ~Menu() {}

	virtual void HandleEvents() = 0;
	virtual void Update(const float& dt) = 0;
	virtual void FixedUpdate(const float& dt) = 0;
	virtual void Draw() = 0;

	virtual void updateMousePosition()
	{
		mousePosScreen = sf::Mouse::getPosition();
		mousePosWindow = sf::Mouse::getPosition(*window);
		mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	}

	void updateKeyTime(const float& dt)
	{
		if (kt < KEYTIME)
			kt += 100.f * dt;
	}

	const bool getKeyTime()
	{
		if (kt >= KEYTIME)
		{
			kt = 0.f;
			return true;
		}
		return false;
	}

	const bool& getQuit() const { return bQuit; }

protected:
	StateManager& sm;
	sf::RenderWindow* window;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	float kt;
	bool bQuit;
};