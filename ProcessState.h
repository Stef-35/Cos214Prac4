#ifndef PROCESSSTATE_H
#define PROCESSSTATE_H

#include <string>

class Unit;

class ProcessState{
    public:
        virtual ~ProcessState() {}
        // Concrete States are responsible for implementing the method
        virtual void advance(Unit* unit) = 0;
        virtual std::string getName() const = 0;
        virtual bool isRepairable() const {return false;}
        virtual bool passedInspection() const {return true;}
        virtual bool isReadyToDispatch() const {return true;}
        virtual bool isDelivered() const {return false;}
};

#endif