#pragma once

#include "States.hpp"

#include <stack>

namespace WAIDT
{
typedef std::unique_ptr<State> STATE_REF;

class StateManager
{
public:
	StateManager() {};
	~StateManager() {};

	void addState(STATE_REF state, bool isReplacing = true);
	void deleteState();

	void handleStateChanges();

	STATE_REF& getCurrentState();

private:
	std::stack<STATE_REF> states;
	STATE_REF newState;

	bool _isAdding;
	bool _isDeleting;
	bool _isReplacing;
};
}