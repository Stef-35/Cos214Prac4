#include "UnitDecorator.h"

double UnitDecorator::getWeight()
{
	// TODO - implement UnitDecorator::getWeight
	throw "Not yet implemented";
}

bool UnitDecorator::hasLabel(const string &label)
{
	return unit->hasLabel(label);
}