#ifndef DROPPED_H
#define DROPPED_H

class Dropped : ProcessState {


public:
	void advance(Unit* unit);

	string getName();
};

#endif
