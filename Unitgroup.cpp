#include "Unitgroup.h"
#include "DepthFirstIterator.h"

double Unitgroup::getWeight()
{
	double total = 0;
	for (Unit *child : children)
	{
		total += child->getWeight();
	}
	return total;
}

bool Unitgroup::remove(Unit *unit)
{
	for (vector<Unit *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (*it == unit)
		{
			children.erase(it);
			return true;
		}
	}
	return false;
}

string Unitgroup::inspect()
{
	return "Group " + id + " weight=" + to_string(getWeight());
}

UnitIterator *Unitgroup::createDepthFirstIterator()
{
	return new DepthFirstIterator();
}

UnitIterator *Unitgroup::createBreadthFirstIterator()
{
	return new BreadthFirstIterator();
}

Unitgroup::~Unitgroup()
{
	for (Unit *child : children)
	{
		delete child;
	}
}

bool Palette::add(Unit *unit)
{
	if (unit == NULL)
	{
		return false;
	}
	children.push_back(unit);
	return true;
}

void Palette::advance()
{
	state->advance(this);
}

string Palette::getStatus()
{
	return state->getName();
}

void Palette::setState(ProcessState *state)
{
	if (state != NULL)
	{
		delete this->state;
		this->state = state;
	}
}

Palette::~Palette()
{
	delete state;
}

bool Container::add(Unit *unit)
{
	if (unit == NULL)
	{
		return false;
	}
	children.push_back(unit);
	return true;
}

Container::~Container() {}
