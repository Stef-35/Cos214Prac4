#include "Faulty.h"

double Faulty::getWeight()
{
	// TODO - implement Faulty::getWeight
	throw "Not yet implemented";
}

string Faulty::inspect()
{
	// TODO - implement Faulty::inspect
	throw "Not yet implemented";
}

bool Faulty::hasLabel(const string &label)
{
	return label == "Faulty" || unit->hasLabel(label);
}