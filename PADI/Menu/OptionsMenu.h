#pragma once
#include "Menu.h"
#include "../UserInterface/Button.h"

class OptionsMenu : public Menu
{
public:
	OptionsMenu(StateManager& sm, sf::RenderWindow* window);
	~OptionsMenu();

	virtual void HandleEvents();
	virtual void Update(const float& dt);
	virtual void FixedUpdate(const float& dt) { }
	virtual void Draw();

private:
	std::map<std::string, Button*> buttons;
	sf::Sprite background;
};