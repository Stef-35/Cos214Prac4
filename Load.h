#ifndef LOAD_H
#define LOAD_H

class Load : ProcessState {


public:
	void advance(Unit* unit);

	string getName();
};

#endif
