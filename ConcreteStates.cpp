#include "ConcreteStates.h"
#include "Unit.h"
#include <iostream>

// Inspect State
Inspect::Inspect(bool passedInspection) : passed(passedInspection){}

void Inspect::advance(Unit* unit) {
    if(this->passed){
        std::cout << "[Inspect -> Load] Check complete. Loading goods...\n";
        unit->setState(new Load());
    } else {
        std::cout << "[Inspect -> Dropped]" Check complete. Dropping goods...\n";
        unit->setState(new Dropped(true));
    }
}

std::string Inspect::getName() const {
        return "Inspect"
}

bool Inspect::passedInspection() const {
        return passed
}

