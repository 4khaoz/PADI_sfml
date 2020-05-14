#include "StateManager.h"
#include "GameInstance.h"

StateManager::StateManager(sf::RenderWindow* win)
	: window { win }
{
	PushMenu(new MainMenu(*this, window));
}

StateManager::~StateManager()
{
	while (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}

void StateManager::PushMenu(Menu* menu)
{
	states.push(menu);
}

void StateManager::PopMenu()
{
	states.pop();
	std::cout << "stack size: " << states.size() << std::endl;
}

void StateManager::ChangeMenu(Menu* menu)
{
	if (!states.empty())
		PopMenu();

	PushMenu(menu);
}

void StateManager::HandleEvents()
{
	if (!states.empty())
		states.top()->HandleEvents();
}

void StateManager::Update(const float& dt)
{
	if (!states.empty())
	{
		states.top()->Update(dt);

		if (states.top()->getQuit())
		{
			delete states.top();
			states.pop();
		}
	}
	else
	{
		window->close();
	}
}

void StateManager::FixedUpdate(const float& dt)
{
	if (!states.empty())
		states.top()->FixedUpdate(dt);
}

void StateManager::Draw()
{
	if (!states.empty())
		states.top()->Draw();
}
