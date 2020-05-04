#pragma once

#include "MainMenu.h"

class StateManager
{
public:
	StateManager(sf::RenderWindow* window);
	~StateManager();

	void PushMenu(Menu* menu);
	void PopMenu();
	void ChangeMenu(Menu* menu);
	
	void HandleEvents();
	void Update(const float& dt);
	void Draw();

	Menu* CurrentMenu() { return states.top(); }

private:
	sf::RenderWindow* window;
	std::stack<Menu*> states;
	
	bool bQuit;
};