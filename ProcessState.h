#ifndef PROCESSSTATE_H
#define PROCESSSTATE_H

class ProcessState {


public:
	virtual void advance(Unit* unit) = 0;

	virtual string getName() = 0;

	virtual void ~ProcessState() = 0;
};

#endif
