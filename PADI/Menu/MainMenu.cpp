#include "MainMenu.h"
#include "../ResourceManager.h"
#include "StateManager.h"
#include "GameInstance.h"

MainMenu::MainMenu(StateManager& sm, sf::RenderWindow* window)
	: Menu(sm, window)
{
	//texture = g_Res->getTextureByName("background");
	background.setTexture(*g_Res->getTextureByName("background"));
	background.setScale(
		(float) 1280 / background.getTexture()->getSize().x,
		(float) 720 / background.getTexture()->getSize().y
	);
	background.setPosition(0, 0);

	buttons["Easy"] = new Button(
		sf::Vector2f(750, 375),
		sf::Vector2f(200, 50),
		"Pleb", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["Normal"] = new Button(
		sf::Vector2f(750, 450),
		sf::Vector2f(200, 50),
		"Normie", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["Hard"] = new Button(
		sf::Vector2f(750, 525),
		sf::Vector2f(200, 50),
		"Tryhard", 24,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

	buttons["Quit"] = new Button(
		sf::Vector2f(750, 600),
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
	if (buttons["Easy"]->isPressed())
		sm.PushMenu(new GameInstance(sm, window, 0));

	if (buttons["Normal"]->isPressed())
		sm.PushMenu(new GameInstance(sm, window, 1));

	if (buttons["Hard"]->isPressed())
		sm.PushMenu(new GameInstance(sm, window, 2));

	if (buttons["Quit"]->isPressed())
		bQuit = true;
}

void MainMenu::Update(const float& dt)
{
	updateMousePosition();
	for (auto it : buttons)
		it.second->Update(mousePosView);
}

void MainMenu::Draw()
{
	this->window->draw(this->background);

	for (auto it : buttons)
		it.second->Draw(*window);
}
