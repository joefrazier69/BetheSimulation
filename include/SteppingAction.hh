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

    // 
    G4double GetTotalDistance() const;
    G4int GetProtonCount() const;
    G4double GetAverageDistance() const;

private:
    G4double totalEnergyDeposited;

    // 
    G4double totalDistance;
    G4int protonCount;
};

#endif
