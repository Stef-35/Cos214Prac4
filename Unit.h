#ifndef UNIT_H
#define UNIT_H

#include "UnitIterator.h"
#include <string>

using namespace std;

class Unit
{

private:
	double weight;
	string id;

public:
	virtual double getWeight() = 0;

	virtual string inspect() = 0;

	virtual string getId() = 0;

	virtual UnitIterator *createIterator() = 0;

	virtual ~Unit() = 0;
};

#endif
