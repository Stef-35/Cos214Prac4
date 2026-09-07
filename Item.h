#ifndef ITEM_H
#define ITEM_H

#include "Unit.h"
#include <string>
#include "ProcessState.h"
#include "ConcreteStates.h"

using namespace std;

class Item : public Unit
{
private:
    ProcessState *state;

public:
    Item(double w, string i) : Unit(w, i), state(new Inspect) {};
    double getWeight();

    string inspect();

    void advance();

    std::string getStatus() const;

    void setState(ProcessState *state);

    ~Item();
};

#endif
