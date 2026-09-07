#include "Unitgroup.h"
#include <iostream>

double Unitgroup::getWeight() const
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
	return new DepthFirstIterator(this);
}

UnitIterator *Unitgroup::createBreadthFirstIterator()
{
	return new BreadthFirstIterator(this);
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

void Palette::inspectChildren()
{
	UnitIterator *it = createDepthFirstIterator();

	for (it->first(); !it->isDone(); it->next())
	{
		Unit *u = it->currentItem();

		std::cout << u->getId() << ": " << u->inspect() << "\n";

		if (u->hasLabel("Faulty"))
		{
			remove(u);
			u->setState(new Dropped(true));
			std::cout << "  -> Removed and marked Dropped (faulty)\n";
		}
	}

	delete it;
	advance();
}

void Palette::advance()
{
	if (state)
	{
		state->advance(this);
	}
}

string Palette::getStatus() const
{
	return state ? state->getName() : "Unknown";
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
