#ifndef CONCRETESTATES_H
#define CONCRETESTATES_H

#include "ProcessState.h"

class Inspect : public ProcessState {
    private:
        bool passed;
    public:
        Inspect(bool passedInspection = true) : passed(passedInspection) {}
        void advance(Unit* unit) override;
        std::string getName() const override;
        bool passedInspection() const override;
};



#endif