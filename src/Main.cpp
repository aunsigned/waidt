#include "Platform/Platform.hpp"

int main()
{
	util::Platform platform;

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScale = platform.getScreenScalingFactor(window.getSystemHandle());

	sf::VideoMode mode {
		static_cast<sf::Uint32>(800.0f * screenScale),
		static_cast<sf::Uint32>(600.0f * screenScale),
	};

	window.create(mode, "game", (sf::Style::Close | sf::Style::Titlebar));

	sf::Event event;

	window.setFramerateLimit(30);
	window.clear();
	window.display();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.display();
	}

	return EXIT_SUCCESS;
}
