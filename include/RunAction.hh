#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "SteppingAction.hh"
#include "globals.hh"
class RunAction : public G4UserRunAction {
public:
    RunAction(SteppingAction* steppingAction);
    virtual ~RunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
private:
    SteppingAction* fSteppingAction;
};

#endif
