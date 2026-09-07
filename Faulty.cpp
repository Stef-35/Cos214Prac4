#include "Faulty.h"

double Faulty::getWeight() const
{
    return unit->getWeight();
}

string Faulty::inspect()
{
    return "Faulty[" + unit->inspect() + "]";
}

bool Faulty::hasLabel(const string &label) const
{
    return label == "Faulty" || unit->hasLabel(label);
}