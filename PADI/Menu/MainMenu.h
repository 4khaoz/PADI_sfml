#pragma once

#include "Menu.h"

class MainMenu : public Menu
{
public:
	MainMenu(StateManager& sm, sf::RenderWindow* window);
	virtual ~MainMenu();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void Draw();

private:



};