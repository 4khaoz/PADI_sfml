#include "InputManager.h"

InputManager* g_Input;

bool InputManager::wasKeyDown(sf::Keyboard::Key key)
{
	auto it = m_KeyMapPrev.find(key);
	if (it != m_KeyMapPrev.end())
		return it->second;

	return false;
}

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
	m_KeyMap.clear();
	m_KeyMapPrev.clear();
}

void InputManager::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}

void InputManager::KeyPressed(sf::Keyboard::Key key)
{
	m_KeyMap[key] = true;
}

void InputManager::KeyReleased(sf::Keyboard::Key key)
{
	m_KeyMap[key] = false;
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key)
{
	return isKeyDown(key) && !wasKeyDown(key);
}

void InputManager::Update()
{
	// Update Keys
	for (auto& it : m_KeyMap)
	{
		m_KeyMapPrev[it.first] = it.second;
	}

	// Update Mouse Position
	MousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

const sf::Vector2f& InputManager::getMousePos() const
{
	return MousePosView;
}

bool InputManager::isKeyDown(sf::Keyboard::Key key)
{
	auto it = m_KeyMap.find(key);
	if (it != m_KeyMap.end())
		return it->second;

	return false;
}
