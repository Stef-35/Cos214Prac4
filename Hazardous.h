#ifndef HAZARDOUS_H
#define HAZARDOUS_H

#include "UnitDecorator.h"
#include <string>

class Hazardous : public UnitDecorator {
public:
    Hazardous(Unit* u) : UnitDecorator(u) {}
    double getWeight() const override;
    string inspect() override;
};

#endif