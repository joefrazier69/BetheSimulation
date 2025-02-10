#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"
#include "G4TouchableHandle.hh"

SteppingAction::SteppingAction() : totalEnergyDeposited(0) {}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    if (volume->GetName() == "Silicon") {
        totalEnergyDeposited += step->GetTotalEnergyDeposit();
    }
    G4Track* track = step->GetTrack();
    G4String particleName = track->GetDefinition()->GetParticleName();
    G4String volumeName = step->GetPreStepPoint()->GetPhysicalVolume()->GetName();
    G4double energyLoss = step->GetTotalEnergyDeposit();
    //G4double stepLength = step->GetStepLength();
    //G4double remainingEnergy = track->GetKineticEnergy();

    // Track only protons
    //if (particleName == "proton") {
        //G4cout << "[PROTON] Energy Loss: " << energyLoss / MeV << " MeV, "
               //<< "Step Length: " << stepLength / mm << " mm, "
               //<< "Remaining Energy: " << remainingEnergy / MeV << " MeV, "
               //<< "Location: " << volumeName << G4endl;
    

    // Detect if proton stops
    //if (remainingEnergy == 0) {
        //G4cout << "[PROTON STOPPED] Final Position: " << track->GetPosition() << G4endl;
    

    // Track energy loss in air vs. silicon
    if (volumeName == "World") {
        G4cout << "[IN AIR] Energy Loss: " << energyLoss / MeV << " MeV" << G4endl;
    } else if (volumeName == "Silicon") {
        G4cout << "[IN SILICON] Energy Loss: " << energyLoss / MeV << " MeV" << G4endl;
    }

    // Detect secondaries
    //if (track->GetParentID() > 0) {
        //G4cout << "[SECONDARY] Created: " << particleName << ", "
               //<< "Energy: " << remainingEnergy / MeV << " MeV" << G4endl;
    
}
