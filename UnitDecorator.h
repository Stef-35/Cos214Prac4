#ifndef UNITDECORATOR_H
#define UNITDECORATOR_H

#include "Unit.h"
#include <string>

class UnitDecorator :public Unit {

public:
	Unit* unit;

	double getWeight();

	virtual std::string inspect() = 0;

	virtual ~UnitDecorator() = 0;
};

#endif
