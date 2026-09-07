#ifndef FAULTY_H
#define FAULTY_H

#include <string>
#include "UnitDecorator.h"

class Faulty : UnitDecorator
{

public:
	double getWeight();
	bool hasLabel(const string &label);
	string inspect();
};

#endif
