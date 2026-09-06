#ifndef UNITGROUP_H
#define UNITGROUP_H

#include "Unit.h"
#include <string>
#include "ProcessState.h"
#include <vector>
#include "UnitIterator.h"
#include "DepthFirstIterator.h"
#include "BreadthFirstIterator.h"

class Unitgroup : public Unit
{
private:
	vector<Unit *> children;

public:
	Unitgroup(double w, string i) : Unit(w, i) {};
	virtual bool add(Unit *unit) = 0;

	virtual bool remove(Unit *unit);

	double getWeight();

	UnitIterator *createDepthFirstIterator();
	UnitIterator *createBreadthFirstIterator();

	virtual ~Unitgroup();
};

class Palette : Unitgroup
{
private:
	ProcessState *state;

public:
	bool add(Unit *unit);

	void advance();

	string getStatus();

	void setState(ProcessState *state);
};

class Container : Unitgroup
{

public:
	bool add(Unit *unit);
};

#endif
