#include "PhysicsList.hh"
#include "G4EmStandardPhysics_option3.hh"  // Faster EM physics
// Alternatively, you can use G4EmLivermorePhysics for low-energy optimizations

PhysicsList::PhysicsList() {
    // Use G4EmStandardPhysics_option3 for faster simulations
    RegisterPhysics(new G4EmStandardPhysics_option3());
}

PhysicsList::~PhysicsList() {}