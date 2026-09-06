#ifndef UNITDECORATOR_H
#define UNITDECORATOR_H

class UnitDecorator : Unit {

public:
	Unit* unit;

	double getWeight();

	virtual string inspect() = 0;

	virtual void ~UnitDecorator() = 0;
};

#endif
