#include "Game.hpp"
#include "states/MainMenuState.hpp"

namespace WAIDT
{
Game::Game(int height, int width, std::string title)
{
	_data->window.create(sf::VideoMode(width, height), title, (sf::Style::Close | sf::Style::Titlebar));

	_data->states.addState(STATE_REF(new MainMenuState(this->_data)));

	this->Run();
};

void Game::Run()
{
	float time, frame_time, interpolation;

	float curr_Time = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen())
	{
		this->_data->states.handleStateChanges();

		time = this->clock.getElapsedTime().asSeconds();
		frame_time = time - curr_Time;

		if (frame_time > 0.25f)
			frame_time = 0.25f;

		curr_Time = time;
		accumulator += frame_time;

		while (accumulator >= dt)
		{
			this->_data->states.getCurrentState()->pollEvents();
			this->_data->states.getCurrentState()->update(dt);

			accumulator = dt;
		}

		interpolation = accumulator / dt;

		this->_data->states.getCurrentState()->render(interpolation);
	}
}
}