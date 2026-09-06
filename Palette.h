#ifndef PALETTE_H
#define PALETTE_H

class Palette : Unitgroup {

public:
	ProcessState* state;

	bool add(Unit* unit);

	void advance();

	string getStatus();

	void setState(ProcessState* state);
};

#endif
