#pragma once

namespace WAIDT
{
class InputManager
{
public:
	InputManager() {};
	virtual ~InputManager() {};

	bool isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button m_Button, sf::RenderWindow& window);

	sf::Vector2i getMousePos(sf::RenderWindow& window);
};
}