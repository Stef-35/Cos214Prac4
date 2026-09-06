#ifndef UNIT_H
#define UNIT_H

#include "UnitIterator.h"
#include <string>

using namespace std;

class Unit
{

protected:
	double weight;
	string id;

public:
	Unit(double w, string i) : weight(w), id(i) {};

	virtual double getWeight() = 0;

	virtual string inspect() = 0;

	virtual string getId() = 0;

	virtual UnitIterator *createDepthFirstIterator() = 0;
	virtual UnitIterator *createBreadthFirstIterator() = 0;

	virtual ~Unit() = 0;
};

#endif
