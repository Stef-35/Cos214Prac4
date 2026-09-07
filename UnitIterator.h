#ifndef UNITITERATOR_H
#define UNITITERATOR_H

class Unit;

class UnitIterator
{

public:
	virtual void first() = 0;

	virtual void next() = 0;

	virtual bool isDone() const = 0;

	virtual Unit *currentItem() const = 0;

	virtual ~UnitIterator() = 0;
};

#endif
