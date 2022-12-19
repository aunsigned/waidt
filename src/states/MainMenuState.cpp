
#include "MainMenuState.hpp"
#include "ASSETS.hpp"
#include "DEFS.hpp"

namespace WAIDT
{
MainMenuState::MainMenuState(data_ref data) :
	_data(data)
{
}

void MainMenuState::init()
{
	this->_data->assets.loadTexture("background", MAIN_MENU_BACKGROUND);
	this->_data->assets.loadTexture("play_button", MAIN_MENU_PLAY_BUTTON);
	this->_data->assets.loadTexture("title", MAIN_MENU_TITLE);

	this->bg.setTexture(this->_data->assets.getTexture("background"));
	this->play_button.setTexture(this->_data->assets.getTexture("play_button"));
	this->title.setTexture(this->_data->assets.getTexture("title"));

	this->play_button.setPosition((SCREEN_WIDTH / 2) - (this->play_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->play_button.getGlobalBounds().height / 2));
	this->title.setPosition((SCREEN_WIDTH / 2) - (this->title.getGlobalBounds().width / 2), this->title.getGlobalBounds().height * 0.1);
}

void MainMenuState::pollEvents()
{
	sf::Event ev;

	while (this->_data->window.pollEvent(ev))
	{
		switch (ev.type)
		{
			case sf::Event::Closed:
				this->_data->window.close();
				break;
		}

		if (this->_data->input.isSpriteClicked(this->play_button, sf::Mouse::Left, this->_data->window))
			std::cout << "Go to game screen" << std::endl;
	}
}

void MainMenuState::update(float d_Time)
{
}

void MainMenuState::render(float d_Time)
{
	this->_data->window.clear();

	this->_data->window.draw(this->bg);
	this->_data->window.draw(this->title);
	this->_data->window.draw(this->play_button);

	this->_data->window.display();
}
}