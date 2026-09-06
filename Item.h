#ifndef ITEM_H
#define ITEM_H

class Item : Unit {

public:
	ProcessState* state;

	double getWeight();

	string inspect();

	void advance();

	string getStatus();

	void setState(ProcessState* state);
};

#endif
