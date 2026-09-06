#ifndef UNITGROUP_H
#define UNITGROUP_H

class Unitgroup : Unit {

public:
	Unit children;

	virtual bool add(Unit* unit) = 0;

	virtual bool remove(Unit* unit) = 0;

	double getWeight();

	UnitIterator createIterator();

	virtual void ~UnitGroup() = 0;
};

#endif
