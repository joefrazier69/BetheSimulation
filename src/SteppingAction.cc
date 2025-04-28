#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"
#include "G4TouchableHandle.hh"
#include <map>
#include <cmath>
#include <iostream>


std::map<G4int, G4double> protonPathLength;
std::map<G4int, G4double> totalBetheEnergyLoss;
std::map<G4int, G4double> totalGeant4EnergyLoss; 

SteppingAction::SteppingAction() : totalEnergyDeposited(0) {}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    G4Track* track = step->GetTrack();
    G4String particleName = track->GetDefinition()->GetParticleName();
    G4String volumeName = step->GetPreStepPoint()->GetPhysicalVolume()->GetName();
    G4double energyLoss = step->GetTotalEnergyDeposit();
    G4double stepLength = step->GetStepLength();
    G4double remainingEnergy = track->GetKineticEnergy();
    G4int trackID = track->GetTrackID(); 

    if (particleName == "proton" && volumeName == "Silicon") {
        totalEnergyDeposited += energyLoss;
        protonPathLength[trackID] += stepLength;
        totalGeant4EnergyLoss[trackID] += energyLoss; 

        

        if (stepLength >= 0.0002 * mm) {
            G4cout << "PROTON Energy Loss (Geant4): " << energyLoss / MeV << " MeV, " << G4endl;
                   
        }
        
    }
    if (particleName == "proton" && (track->GetTrackStatus() == fStopAndKill || volumeName != "Silicon")) {
        G4cout << "Proton " << trackID << " traveled a total distance of: "
               << protonPathLength[trackID] / mm << " mm inside silicon." << G4endl;
        

        protonPathLength.erase(trackID);
        
    }

    if (remainingEnergy == 0) {
        G4cout << "PROTON STOPPED at Position: " << track->GetPosition() << G4endl;
    }
}
