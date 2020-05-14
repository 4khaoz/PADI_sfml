#pragma once
#include "Menu.h"
#include "../UserInterface/Button.h"

class OptionsMenu : public Menu
{
public:
	OptionsMenu(StateManager& sm, sf::RenderWindow* window);
	~OptionsMenu();


private:
	std::map<std::string, Button*> buttons;
};