#ifndef SHIP_H
#define SHIP_H

class Ship : ProcessState {


public:
	void advance(Unit* unit);

	string getName();
};

#endif
