#pragma once

#include "Platform/Platform.hpp"

namespace WAIDT
{
class State
{
public:
	virtual void init() = 0;

	const bool getWindowIsOpen() const;

	virtual void pollEvents() = 0;
	virtual void update(float d_Time) = 0;
	virtual void render(float d_Time) = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;
};
}