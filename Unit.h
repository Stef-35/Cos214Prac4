#ifndef UNIT_H
#define UNIT_H

#include <string>

class UnitIterator;
class ProcessState;

using namespace std;

class Unit
{

protected:
	double weight;
	string id;

public:
	Unit(double w, string i) : weight(w), id(i) {};

	virtual double getWeight() const = 0;

	virtual string inspect() = 0;

	virtual string getId() const { return id; }

	virtual void setState(ProcessState *state) {}

	virtual bool hasLabel(const string &label) const { return false; }

	virtual UnitIterator *createDepthFirstIterator() = 0;
	virtual UnitIterator *createBreadthFirstIterator() = 0;

	virtual ~Unit() = 0;
};

#endif
