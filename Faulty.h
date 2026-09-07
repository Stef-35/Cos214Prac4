#ifndef FAULTY_H
#define FAULTY_H

#include <string>
#include "UnitDecorator.h"

class Faulty : public UnitDecorator {
public:
    Faulty(Unit* u) : UnitDecorator(u) {}
    double getWeight() const override;
    bool hasLabel(const string &label) const override;
    string inspect() override;
};

#endif