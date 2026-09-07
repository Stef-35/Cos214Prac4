#ifndef UNITDECORATOR_H
#define UNITDECORATOR_H

#include "Unit.h"

#include <string>

class UnitDecorator : public Unit
{
protected:
	Unit *unit;

public:
	double getWeight();

	virtual std::string inspect() = 0;
	bool hasLabel(const string &label);
	virtual ~UnitDecorator() = 0;
};

#endif
