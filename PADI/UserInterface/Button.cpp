#include "Button.h"
#include "../ResourceManager.h"

Button::Button(
	sf::Vector2f pos,
	sf::Vector2f size,
	std::string text,
	int textSize,
	sf::Color idle,
	sf::Color hover,
	sf::Color clicked
) : idle(idle), hover(hover), clicked(clicked)
{
	this->shape.setPosition(pos);
	this->shape.setSize(size);

	this->text.setFont(*g_Res->getFont());
	this->text.setCharacterSize(textSize);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(
		shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->shape.setFillColor(this->idle);
}

Button::~Button()
{
}

void Button::Update(const sf::Vector2f pos)
{

	btn_state = button_state::B_IDLE;

	if (shape.getGlobalBounds().contains(pos))
	{
		btn_state = button_state::B_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			btn_state = button_state::B_CLICKED;
	}

	switch (btn_state)
	{
	case button_state::B_IDLE:
		shape.setFillColor(idle);
		break;
	case button_state::B_HOVER:
		shape.setFillColor(hover);
		break;
	case button_state::B_CLICKED:
		shape.setFillColor(clicked);
		break;
	default:
		shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::Draw(sf::RenderTarget& target)
{
	target.draw(shape);
	target.draw(text);
}

const bool Button::isPressed() const
{
	if (btn_state == button_state::B_CLICKED)
		return true;

	return false;
}
