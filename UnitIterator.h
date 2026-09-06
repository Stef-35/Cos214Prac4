#ifndef UNITITERATOR_H
#define UNITITERATOR_H

class UnitIterator {


public:
	virtual void first() = 0;

	virtual void next() = 0;

	virtual void isDone() = 0;

	virtual Unit* currentItem() = 0;

	virtual ~UnitIterator() = 0;
};

#endif