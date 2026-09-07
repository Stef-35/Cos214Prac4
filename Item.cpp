#include "Item.h"

double Item::getWeight() const
{
	return weight;
}

string Item::inspect()
{
	return "Inspected passed";
}

void Item::advance()
{
	if (state)
	{
	state->advance(this);
	}
}

string Item::getStatus() const
{
	return state ? state->getName() : "Unknown";
}

void Item::setState(ProcessState *state)
{
	if (state != NULL)
	{
		delete this->state;
		this->state = state;
	}
}

Item::~Item()
{
	delete state;
}
