#include "PhysicsList.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4IonPhysics.hh"

//#include "G4EmLivermorePhysics.hh"
//#include "G4EmParameters.hh"
//#include "G4EmPenelopePhysics.hh"
//#include "G4EmStandardPhysics.hh"
//#include "G4EmStandardPhysics_option1.hh"
//#include "G4EmStandardPhysics_option2.hh"
#include "G4EmStandardPhysics_option3.hh"
//#include "G4EmStandardPhysics_option4.hh"
#include "G4LossTableManager.hh"

PhysicsList::PhysicsList() {
    //RegisterPhysics(new G4EmPenelopePhysics());// Electromagnetic interactions
    //RegisterPhysics(new G4EmStandardPhysics_option1()); 
    //RegisterPhysics(new G4EmStandardPhysics_option2()); 
    RegisterPhysics(new G4EmStandardPhysics_option3()); 
    //RegisterPhysics(new G4EmStandardPhysics_option4()); 
    RegisterPhysics(new G4HadronPhysicsFTFP_BERT());    // Hadronic interactions
    //RegisterPhysics(new G4EmLivermorePhysics());
    //RegisterPhysics(new G4IonPhysics());               // Ion physics 
}

PhysicsList::~PhysicsList() {}
