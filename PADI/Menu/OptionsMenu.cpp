#include "OptionsMenu.h"
#include "../ResourceManager.h"
#include "StateManager.h"

OptionsMenu::OptionsMenu(StateManager& sm, sf::RenderWindow* window)
	: Menu(sm, window)
{
	background.setTexture(*g_Res->getTextureByName("optionsbackground"));
	background.setScale(
		(float)1280 / background.getTexture()->getSize().x,
		(float)720 / background.getTexture()->getSize().y
	);
	background.setPosition(0, 0);

	buttons["SFX_Low"] = new Button(
		sf::Vector2f(1000, 100),
		sf::Vector2f(150, 50),
		"Low SFX", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["SFX_Med"] = new Button(
		sf::Vector2f(1000, 175),
		sf::Vector2f(150, 50),
		"Medium SFX", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["SFX_High"] = new Button(
		sf::Vector2f(1000, 250),
		sf::Vector2f(150, 50),
		"High SFX", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["BGM_Low"] = new Button(
		sf::Vector2f(100, 100),
		sf::Vector2f(150, 50),
		"Low BGM", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["BGM_Med"] = new Button(
		sf::Vector2f(100, 175),
		sf::Vector2f(150, 50),
		"Medium BGM", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["BGM_High"] = new Button(
		sf::Vector2f(100, 250),
		sf::Vector2f(150, 50),
		"High BGM", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["Save"] = new Button(
		sf::Vector2f(1100, 575),
		sf::Vector2f(150, 50),
		"Save", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["Back"] = new Button(
		sf::Vector2f(1100, 650),
		sf::Vector2f(150, 50),
		"Back", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
}

OptionsMenu::~OptionsMenu()
{
	for (auto it : buttons)
		delete it.second;
}

void OptionsMenu::HandleEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		sm.PopMenu();

	if (buttons["SFX_Low"]->isPressed() && getKeyTime())
		g_Res->setSFXVolume(0);
	if (buttons["SFX_Med"]->isPressed() && getKeyTime())
		g_Res->setSFXVolume(1);
	if (buttons["SFX_High"]->isPressed() && getKeyTime())
		g_Res->setSFXVolume(2);

	if (buttons["BGM_Low"]->isPressed() && getKeyTime())
		g_Res->setBGMVolume(0);
	if (buttons["BGM_Med"]->isPressed() && getKeyTime())
		g_Res->setBGMVolume(1);
	if (buttons["BGM_High"]->isPressed() && getKeyTime())
		g_Res->setBGMVolume(2);

	if (buttons["Save"]->isPressed() && getKeyTime())
		g_Res->SaveSettings();
	if (buttons["Back"]->isPressed() && getKeyTime())
		sm.PopMenu();
}

void OptionsMenu::Update(const float& dt)
{
	updateMousePosition();
	updateKeyTime(dt);
	for (auto it : buttons)
		it.second->Update(mousePosView);
}

void OptionsMenu::Draw()
{
	this->window->draw(this->background);

	for (auto it : buttons)
		it.second->Draw(*window);
}
