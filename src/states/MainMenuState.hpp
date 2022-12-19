#pragma once

#include "../Game.hpp"
#include "../States.hpp"

namespace WAIDT
{
class MainMenuState : public State
{
public:
	MainMenuState(data_ref data);

	void init();

	void pollEvents();
	void update(float d_Time);
	void render(float d_Time);

private:
	data_ref _data;

	// Background
	sf::Sprite bg;
	// play button
	sf::Sprite play_button;
	// main title
	sf::Sprite title;
};
}