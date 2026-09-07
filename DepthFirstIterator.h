#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "Unit.h"
#include "UnitIterator.h"
#include <stack>

class DepthFirstIterator : public UnitIterator
{

private:
	stack<Unit *> stack;
	Unit *curr;
	Unit *lookup;

public:
	DepthFirstIterator(Unit *rootUnit);
	void first();

	void next();

	bool isDone();

	Unit *currentItem();
};

#endif
