#include "InputManager.hpp"

namespace WAIDT
{
bool InputManager::isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button m_Button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(m_Button))
	{
		sf::IntRect rect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

		if (rect.contains(sf::Mouse::getPosition(window)))
			return true;

		return false;
	}
}

sf::Vector2i InputManager::getMousePos(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}
}