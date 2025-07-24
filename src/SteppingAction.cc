#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"
#include "G4TouchableHandle.hh"
#include <map>
#include <cmath>
#include <iostream>

// Global tracking maps
std::map<G4int, G4double> protonPathLength;
std::map<G4int, G4double> totalGeant4EnergyLoss;

SteppingAction::SteppingAction()
    : totalEnergyDeposited(0), totalDistance(0.0), protonCount(0) {}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    G4Track* track = step->GetTrack();
    G4String particleName = track->GetDefinition()->GetParticleName();
    G4StepPoint* prePoint = step->GetPreStepPoint();
    G4StepPoint* postPoint = step->GetPostStepPoint();

    G4VPhysicalVolume* preVolume = prePoint->GetPhysicalVolume();
    G4VPhysicalVolume* postVolume = postPoint->GetPhysicalVolume();

    G4double energyLoss = step->GetTotalEnergyDeposit();
    G4double stepLength = step->GetStepLength();
    G4int trackID = track->GetTrackID();

    if (particleName == "proton") {
        G4String preName = preVolume ? preVolume->GetName() : "";
        G4String postName = postVolume ? postVolume->GetName() : "";

        // Proton inside silicon
        if (preName == "Silicon" && postName == "Silicon") {
            totalEnergyDeposited += energyLoss;
            protonPathLength[trackID] += stepLength;
            totalGeant4EnergyLoss[trackID] += energyLoss;

            if (stepLength >= 0.0002 * mm) {
                G4cout << "PROTON Energy Loss in Silicon: " << energyLoss / MeV << " MeV" << G4endl;
            }
        }

        // Proton ends
        if (track->GetTrackStatus() == fStopAndKill) {
            if (protonPathLength.count(trackID)) {
                G4double distance = protonPathLength[trackID];
                G4cout << "Proton " << trackID
                       << " total distance in Silicon: " << distance / mm << " mm" << G4endl;

                totalDistance += distance;
                protonCount++;

                protonPathLength.erase(trackID);
                totalGeant4EnergyLoss.erase(trackID);
            }
        }
    }
}

// Add these getter methods in your SteppingAction.hh file as well:
G4double SteppingAction::GetTotalDistance() const {
    return totalDistance;
}

//G4int SteppingAction::GetProtonCount() const {
 //   return protonCount;
//}

G4double SteppingAction::GetAverageDistance() const {
    return protonCount > 0 ? totalDistance / 1000 : 0.0;
}
