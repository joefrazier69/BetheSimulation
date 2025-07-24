#include "RunAction.hh"
#include "G4Run.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"

RunAction::RunAction(SteppingAction* steppingAction) : fSteppingAction(steppingAction) {}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run* run) {
    G4cout << "### Run " << run->GetRunID() << " started." << G4endl;
}

void RunAction::EndOfRunAction(const G4Run* run) {
    G4cout << "### Run " << run->GetRunID() << " ended." << G4endl;

    
    G4double totalEnergyDeposited = fSteppingAction->GetTotalEnergyDeposited();


    G4double thickness = 0.2 * cm;
    G4double width = 1.0 * cm;
    G4double height = 1.0 * cm;
    G4double volume = thickness * width * height;  


    G4Material* silicon = G4NistManager::Instance()->FindOrBuildMaterial("G4_Si");
    G4double density = silicon->GetDensity();  

    G4double mass = density * volume;

    G4double dose = totalEnergyDeposited / mass;
    G4double avgDistance = fSteppingAction->GetAverageDistance();

    G4cout << "Average Path Length in Silicon: "
       << G4BestUnit(avgDistance, "Length") << G4endl;


    G4cout << "Detector Volume: " << G4BestUnit(volume, "Volume") << G4endl;
    G4cout << "Detector Mass:   " << G4BestUnit(mass, "Mass") << G4endl;
    G4cout << "Total Energy Deposited: " << G4BestUnit(totalEnergyDeposited, "Energy") << G4endl;
    G4cout << "Absorbed Dose:          " << G4BestUnit(dose, "Dose") << G4endl;
}
