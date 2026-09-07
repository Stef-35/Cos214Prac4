#include "Item.h"

double Item::getWeight()
{
	return weight;
}

string Item::inspect()
{
	return "Inspected passed";
}

void Item::advance()
{
	state->advance(this);
}

string Item::getStatus() const
{
	return state->getName();
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
