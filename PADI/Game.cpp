#include "Game.h"
#include "ResourceManager.h"

Game::Game()
{
	this->vidmode.width = WIN_WIDTH;
	this->vidmode.height = WIN_HEIGHT;

	g_Res->LoadSettings();

	window = new sf::RenderWindow(this->vidmode, TITLE, sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(WIN_FRAMECAP);
	window->setVerticalSyncEnabled(false);

	g_Input->setWindow(window);

	sm = new StateManager(window);
}

Game::~Game()
{
	delete window;
	delete sm;
}

void Game::run()
{
	float accumulator = 0.f;
	while (window->isOpen())
	{
		dt = clock.restart().asSeconds();
		accumulator += dt;

		if (window->hasFocus())
			HandleEvents();

		while (accumulator >= FIXED_UPDATE_TIME)
		{
			sm->FixedUpdate(FIXED_UPDATE_TIME);
			accumulator -= FIXED_UPDATE_TIME;
		}

		sm->Update(dt);
		window->clear();
		sm->Draw();
		window->display();
	}
}

void Game::HandleEvents()
{
	g_Input->Update();
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			g_Input->KeyPressed(e.key.code);
			break;
		case sf::Event::KeyReleased:
			g_Input->KeyReleased(e.key.code);
			break;
		}
	}
	sm->HandleEvents();
}
