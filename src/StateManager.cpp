#include "StateManager.hpp"

namespace WAIDT
{
void StateManager::addState(STATE_REF state, bool isReplacing)
{
	this->_isAdding = true;
	this->_isReplacing = isReplacing;

	this->newState = std::move(newState);
}

void StateManager::deleteState()
{
	this->_isDeleting = true;
}

void StateManager::handleStateChanges()
{
	if (this->_isDeleting && !this->states.empty())
	{
		this->states.pop();

		if (!this->states.empty())
			this->states.top()->resume();

		this->_isDeleting = false;
	}

	if (this->_isAdding)
	{
		if (this->states.empty() && !this->_isReplacing)
			this->states.top()->pause();

		if (!this->states.empty() && this->_isReplacing)
			this->states.pop();

		this->states.push(std::move(this->newState));
		this->states.top()->init();

		this->_isAdding = FALSE;
	}
}

STATE_REF& StateManager::getCurrentState()
{
	return this->states.top();
}

}