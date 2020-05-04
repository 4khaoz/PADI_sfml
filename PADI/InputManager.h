#pragma once

#include "global.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	void setWindow(sf::RenderWindow* window);

	void KeyPressed(sf::Keyboard::Key key);
	void KeyReleased(sf::Keyboard::Key key);

	bool isKeyDown(sf::Keyboard::Key key);
	bool isKeyPressed(sf::Keyboard::Key key);

	void Update();

	const sf::Vector2f& getMousePos() const;

private:
	sf::RenderWindow* window;

	std::map<sf::Keyboard::Key, bool> m_KeyMap;
	std::map<sf::Keyboard::Key, bool> m_KeyMapPrev;

	sf::Vector2f MousePosView;

	bool wasKeyDown(sf::Keyboard::Key);
};