#ifndef UNITDECORATOR_H
#define UNITDECORATOR_H

#include "Unit.h"
#include <string>

class UnitDecorator : public Unit
{
protected:
    Unit *unit;

public:
    UnitDecorator() : Unit(0, "") {}
    UnitDecorator(Unit* u) : Unit(u->getWeight(), u->getId()), unit(u) {}
    
    double getWeight() const override;
    virtual std::string inspect() override;
    bool hasLabel(const string &label) const override;
    virtual ~UnitDecorator() {
        delete unit;
    }


	UnitIterator* createDepthFirstIterator() override { return nullptr; }
    UnitIterator* createBreadthFirstIterator() override { return nullptr; }
};

#endif