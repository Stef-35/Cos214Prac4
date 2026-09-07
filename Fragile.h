#ifndef FRAGILE_H
#define FRAGILE_H

#include "UnitDecorator.h"
#include <string>

class Fragile : public UnitDecorator {
public:
    Fragile(Unit* u) : UnitDecorator(u) {}
    double getWeight() const override;
    string inspect() override;
};

#endif