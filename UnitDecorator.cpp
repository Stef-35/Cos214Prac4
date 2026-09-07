#include "UnitDecorator.h"

double UnitDecorator::getWeight() const
{
    return unit->getWeight();
}

bool UnitDecorator::hasLabel(const string &label) const
{
    return unit->hasLabel(label);
}

string UnitDecorator::inspect()
{
    return unit->inspect();
}