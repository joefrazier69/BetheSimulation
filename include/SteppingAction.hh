#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction();
    virtual ~SteppingAction();

    virtual void UserSteppingAction(const G4Step* step);
    G4double GetTotalEnergyDeposited() const { return totalEnergyDeposited; }

private:
    G4double totalEnergyDeposited;
};


#endif
