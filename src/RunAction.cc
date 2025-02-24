#include "RunAction.hh"
#include "G4Run.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"   

RunAction::RunAction(SteppingAction* steppingAction) : fSteppingAction(steppingAction) {}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run* run) {
    G4cout << "### Run " << run->GetRunID() << " started." << G4endl;
}

void RunAction::EndOfRunAction(const G4Run* run) {
    G4cout << "### Run " << run->GetRunID() << " ended." << G4endl;

     
    G4double totalEnergyDeposited = fSteppingAction->GetTotalEnergyDeposited();
    G4double mass = 2.329 * kg;   
    G4double dose = totalEnergyDeposited / mass;

     
    G4cout << "Total Energy Deposited: " << G4BestUnit(totalEnergyDeposited, "Energy") << G4endl;
    G4cout << "Absorbed Dose: " << G4BestUnit(dose, "Dose") << G4endl;
}
