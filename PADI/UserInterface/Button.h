#pragma once
#include "../global.h"

enum class button_state
{
	B_IDLE,
	B_HOVER,
	B_CLICKED
};

class Button
{
public:
	/**
	@param pos Position
	@param size Size
	@param text Text
	@param textSize TextSize
	@param idle Idle Color
	@param hover Hover Color
	@param clicked Click Color
	*/
	Button(
		sf::Vector2f pos,
		sf::Vector2f size,
		std::string text,
		int textSize,
		sf::Color idle,
		sf::Color hover,
		sf::Color clicked
	);
	~Button();

	void Update(const sf::Vector2f pos);
	void Draw(sf::RenderTarget& target);
	void SetText(std::string str);

	const bool isPressed() const;

private:
	sf::RectangleShape shape;
	sf::Text text;

	sf::Color idle;
	sf::Color hover;
	sf::Color clicked;

	button_state btn_state;
};