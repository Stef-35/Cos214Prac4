#include "Hazardous.h"

double Hazardous::getWeight() const {
    return unit->getWeight();
}

string Hazardous::inspect() {
    return "Hazardous[" + unit->inspect() + "]";
}