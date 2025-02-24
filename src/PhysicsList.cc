#include "PhysicsList.hh"
#include "G4EmStandardPhysics_option3.hh"   

PhysicsList::PhysicsList() {
    
    RegisterPhysics(new G4EmStandardPhysics_option3());
}

PhysicsList::~PhysicsList() {}
