#ifndef INSPECT_H
#define INSPECT_H

class Inspect : ProcessState {


public:
	void advance(Unit* unit);

	string getName();
};

#endif
