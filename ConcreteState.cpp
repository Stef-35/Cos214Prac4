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

// Ship State
Ship::Ship(bool drop, bool confirmed) : accidentalDrop(drop), deliveryConfirmed(confirmed) {}

void Ship::advance(Unit* unit) {
    if (accidentalDrop) {
        std::cout << "[Ship -> Dropped] Accidental drop during transit!\n";
        unit->setState(new Dropped(true));
    } else if (deliveryConfirmed) {
        std::cout << "[Ship -> Delivered] Confirm Delivery. Terminal state reached.\n";
    }
}

std::string Ship::getName() const {
    return "Ship";
}

// Dropped State
Dropped::Dropped(bool repairable) : repairable(repairable) {}

void Dropped::advance(Unit* unit){
    if(this->repairable){
        std::cout << "[Dropped -> Inspect] Item is repairable. Re-inspecting goods...\n";
        unit->setState(new Inspect());
    } else {
        std::cout << "[Dropped -> Scrapped] Item is not repairable. Item scrapped!\n";
    }
}

std::string Dropped::getName() const {
    return "Dropped";
}

bool Dropped::isRepairable() const {
    return repairable;
}