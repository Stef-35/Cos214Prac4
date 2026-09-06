#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "Unit.h"
#include <stack>

class DepthFirstIterator : public UnitIterator
{

private:
	stack<Unit *> stack;
	Unit *curr;
	Unit *lookup;

public:
	void first();

	void next();

	void isDone();

	Unit *currentItem();
};

#endif
