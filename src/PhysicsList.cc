#include "PhysicsList.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4IonPhysics.hh"

PhysicsList::PhysicsList() {
    RegisterPhysics(new G4EmStandardPhysics_option4());  // Electromagnetic interactions
    RegisterPhysics(new G4HadronPhysicsFTFP_BERT());    // Hadronic interactions
    RegisterPhysics(new G4IonPhysics());               // Ion physics 
}

PhysicsList::~PhysicsList() {}
