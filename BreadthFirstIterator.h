#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "Unit.h"
#include <queue>

class BreadthFirstIterator : public UnitIterator
{

private:
	queue<Unit *> queue;
	Unit *curr;

public:
	void first();

	void next();

	void isDone();

	Unit *currentItem();
};

#endif
