#include "AssetManager.hpp"

namespace WAIDT
{
void AssetManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture _texture;

	if (_texture.loadFromFile(fileName))
		this->_textures[name] = _texture;
}

void AssetManager::loadFont(std::string name, std::string fileName)
{
	sf::Font _font;

	if (_font.loadFromFile(fileName))
		this->_fonts[name] = _font;
}

sf::Texture& AssetManager::getTexture(std::string name)
{
	return this->_textures.at(name);
}

sf::Font& AssetManager::getFont(std::string name)
{
	return this->_fonts.at(name);
}
}