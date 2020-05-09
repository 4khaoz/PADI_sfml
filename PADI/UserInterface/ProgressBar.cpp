#include "ProgressBar.h"
#include "../ResourceManager.h"

ProgressBar::ProgressBar(sf::Vector2f position, sf::Vector2f size, sf::Color color, float maxValue, bool bShowNumbers)
	: maxValue(maxValue), bShowNumbers(bShowNumbers)
{
	PBOuter.setPosition(position);
	PBOuter.setSize(size);
	PBOuter.setFillColor(sf::Color::White);

	PBInner.setPosition(position);
	PBInner.setSize(size);
	PBInner.setFillColor(color);

	PBText.setFont(*g_Res->getFont());
	PBText.setFillColor(sf::Color::Black);
	PBText.setCharacterSize(20);
	PBText.setPosition(
		PBInner.getPosition().x + (float) PBInner.getSize().x * 0.8f,
		PBInner.getPosition().y
	);

	PBText.setOrigin(
		PBText.getGlobalBounds().width / 2,
		PBText.getGlobalBounds().height / 2
	);
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::Update(const int val)
{
	float percentage = static_cast<float>(val) / static_cast<float>(maxValue);
	
	PBInner.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(PBOuter.getSize().x * percentage)),
			PBInner.getSize().y
		)
	);

	if (bShowNumbers)
	{
		PBStr = std::to_string(val) + " / " + std::to_string(static_cast<int>(maxValue));
		PBText.setString(PBStr);
	}
}

void ProgressBar::Draw(sf::RenderTarget& target)
{
	target.draw(this->PBOuter);
	target.draw(this->PBInner);

	if (bShowNumbers)
		target.draw(this->PBText);
}
