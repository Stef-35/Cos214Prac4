#include "Fragile.h"

double Fragile::getWeight() const {
    return unit->getWeight();
}

string Fragile::inspect() {
    return "Fragile[" + unit->inspect() + "]";
}