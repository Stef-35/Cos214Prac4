#ifndef UNITGROUP_H
#define UNITGROUP_H

#include "Unit.h"
#include <string>
#include "ProssessState"
#include <vector>

class Unitgroup : public Unit
{
private:
	vector<Unit *> children;

public:
	virtual bool add(Unit *unit) = 0;

	virtual bool remove(Unit *unit) = 0;

	double getWeight();

	UnitIterator *createIterator();

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
