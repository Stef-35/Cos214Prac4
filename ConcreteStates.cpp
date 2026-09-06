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
        std::cout << "[Inspect -> Dropped] Check complete. Dropping goods...\n";
        unit->setState(new Dropped(true));
    }
}

std::string Inspect::getName() const {
        return "Inspect";
}

bool Inspect::passedInspection() const {
        return passed;
}

// Load State
Load::Load(bool drop) : accidentalDrop(drop) {}

void Load::advance(Unit* unit) {
    if (accidentalDrop){
        std::cout << "[Load -> Dropped] Accidental drop during loading!\n";
        unit->setState(new Dropped(false));
    } else {
        std::cout << "[Load -> Ship] Load complete. Dispatching...\n";
        unit->setState(new Ship());
    }
}

std::string Load::getName() const {
    return "Load";
}

