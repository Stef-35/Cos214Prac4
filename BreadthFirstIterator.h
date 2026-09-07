#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "Unit.h"
#include "UnitIterator.h"
#include <queue>

class BreadthFirstIterator : public UnitIterator
{

private:
	std::queue<Unit *> queue;
	Unit *curr;
	Unit *lookup;

public:
	BreadthFirstIterator(Unit *rootUnit);
	void first();

	void next();

	bool isDone();

	Unit *currentItem();
};

#endif
