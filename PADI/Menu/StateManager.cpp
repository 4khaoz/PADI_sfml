#include "StateManager.h"
#include "GameInstance.h"

StateManager::StateManager(sf::RenderWindow* win)
	: window { win }
{
	//PushMenu(new MainMenu(*this, window));
	PushMenu(new GameInstance(*this, window));
}

StateManager::~StateManager()
{
}

void StateManager::PushMenu(Menu* menu)
{
	states.push(menu);
}

void StateManager::PopMenu()
{
	states.pop();
}

void StateManager::ChangeMenu(Menu* menu)
{
	if (!states.empty())
		PopMenu();

	PushMenu(menu);
}

void StateManager::HandleEvents()
{
	states.top()->HandleEvents();
}

void StateManager::Update(const float& dt)
{
	states.top()->Update(dt);
}

void StateManager::Draw()
{
	states.top()->Draw();
}
