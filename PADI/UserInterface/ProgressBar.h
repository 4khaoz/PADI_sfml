#pragma once
#include "../global.h"


class ProgressBar
{
public:
	ProgressBar(
		sf::Vector2f position,
		sf::Vector2f size,
		sf::Color color,
		float maxValue,
		bool bShowNumbers
	);
	~ProgressBar();

	void Update(const int val);
	void Draw(sf::RenderTarget& target);

private:
	bool bShowNumbers;
	sf::Font font;
	float maxValue;
	std::string PBStr;
	sf::Text PBText;
	sf::RectangleShape PBOuter;
	sf::RectangleShape PBInner;
};