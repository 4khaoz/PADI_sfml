#include "MainMenu.h"
#include "../ResourceManager.h"
#include "StateManager.h"
#include "GameInstance.h"

MainMenu::MainMenu(StateManager& sm, sf::RenderWindow* window)
	: Menu(sm, window)
{
	texture = g_Res->getTextureByName("background");
	background.setTexture(texture);
	background.setScale(
		(float) 1280 / background.getTexture()->getSize().x,
		(float) 720 / background.getTexture()->getSize().y
	);
	background.setPosition(0, 0);

	buttons["Play"] = new Button(
		sf::Vector2f(750, 370),
		sf::Vector2f(200, 50),
		"Play Game", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["Quit"] = new Button(
		sf::Vector2f(750, 470),
		sf::Vector2f(200, 50),
		"Quit", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
}

MainMenu::~MainMenu()
{
	for (auto it : buttons)
	{
		delete it.second;
	}
}

void MainMenu::HandleEvents()
{
	if (buttons["Play"]->isPressed())
	{
		sm.PushMenu(new GameInstance(sm, window));
	}

	if (buttons["Quit"]->isPressed())
	{
		bQuit = true;
	}
}

void MainMenu::Update(const float& dt)
{
	updateMousePosition();
	for (auto it : buttons)
	{
		it.second->Update(mousePosView);
	}
}

void MainMenu::Draw()
{
	this->window->draw(this->background);

	for (auto it : buttons)
	{
		it.second->Draw(*window);
	}
}
