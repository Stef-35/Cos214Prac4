#include "Unitgroup.h"

double Unitgroup::getWeight()
{
	double total = 0;
	for (Unit *child : children)
	{
		total += child->getWeight();
	}
	return total;
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
	
}

void Palette::advance()
{
	// TODO - implement Palette::advance
	throw "Not yet implemented";
}

string Palette::getStatus()
{
	// TODO - implement Palette::getStatus
	throw "Not yet implemented";
}

void Palette::setState(ProcessState *state)
{
	// TODO - implement Palette::setState
	throw "Not yet implemented";
}

bool Container::add(Unit *unit)
{
	// TODO - implement Container::add
	throw "Not yet implemented";
}
