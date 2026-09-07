#ifndef ITEM_H
#define ITEM_H

#include "Unit.h"
#include <string>
#include "ProcessState.h"
#include "ConcreteState.h"

using namespace std;

class Item : public Unit
{
private:
    ProcessState *state;

public:
    Item(double w, string i) : Unit(w, i), state(new Inspect()) {};
    double getWeight() const override;

    string inspect() override;

    void advance();

    std::string getStatus() const;

    void setState(ProcessState *state) override;

    UnitIterator *createDepthFirstIterator() override { return nullptr; }
    UnitIterator *createBreadthFirstIterator() override { return nullptr; }

    ~Item();
};

#endif
