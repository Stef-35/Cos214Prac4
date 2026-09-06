#ifndef CONCRETESTATES_H
#define CONCRETESTATES_H

#include "ProcessState.h"

// Inspect State
class Inspect : public ProcessState {
    private:
        bool passed;
    public:
        Inspect(bool passedInspection = true);
        void advance(Unit* unit) override;
        std::string getName() const override;
        bool passedInspection() const override;
};

// Load State
class Load : public ProcessState {
    private:
        bool accidentalDrop;
    public:
        Load(bool drop = false);
        void advance(Unit* unit) override;
        std::string getName() const override;
};

//Ship State
class Ship : public ProcessState {
    private:
        bool accidentalDrop;
        bool deliveryConfirmed;
    public:
        Ship(bool drop = false, bool confirmed = true);
        void advance(Unit* unit) override;
        std::string getName() const override;
};

// Dropped State
class Dropped : public ProcessState {
    private:
        bool repairable;
    public:
        Dropped(bool repairable = true);
        void advance(Unit* unit) override;
        std::string getName() const override;
        bool isRepairable() const override;
};


#endif