#pragma once

#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "StateManager.hpp"

namespace WAIDT
{

struct Data
{
	StateManager states;
	AssetManager assets;
	InputManager input;

	sf::RenderWindow window;
};

typedef std::shared_ptr<Data> data_ref;

class Game
{
public:
	Game(int height, int width, std::string title);

private:
	sf::Clock clock;
	const float dt = 1.0f / 60.0f;

	data_ref _data = std::make_shared<Data>();

	void Run();
};
}