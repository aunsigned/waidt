#pragma once

#include "Platform/Platform.hpp"

namespace WAIDT
{
class State
{
public:
	virtual void init();

	const bool getWindowIsOpen() const;

	virtual void pollEvents();
	virtual void update();
	virtual void render(float d_Time);

	virtual void pause();
	virtual void resume();
};
}