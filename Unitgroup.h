#ifndef UNITGROUP_H
#define UNITGROUP_H

#include "Unit.h"
#include <string>
#include "ProcessState.h"
#include <vector>
#include "UnitIterator.h"
#include "DepthFirstIterator.h"
#include "BreadthFirstIterator.h"
#include "ConcreteStates.h"

class Unitgroup : public Unit
{
protected:
	std::vector<Unit *> children;

public:
	Unitgroup(double w, string i) : Unit(w, i) {};
	virtual bool add(Unit *unit) = 0;

	virtual bool remove(Unit *unit);

	double getWeight();
	string inspect();

	UnitIterator *createDepthFirstIterator();
	UnitIterator *createBreadthFirstIterator();

	virtual ~Unitgroup();
};

class Palette : public Unitgroup
{
private:
	ProcessState *state;

public:
	Palette(double w, string i) : Unitgroup(w, i), state(new Inspect()) {};

	bool add(Unit *unit);

	void advance();

	string getStatus();

	void setState(ProcessState *state);

	~Palette();
};

class Container : public Unitgroup
{

public:
	Container(double w, string i) : Unitgroup(w, i) {};
	bool add(Unit *unit);
	~Container();
};

#endif
