#ifndef PHYSICSLIST_HH
#define PHYSICSLIST_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics_option4.hh"  // Electromagnetic physics
#include "G4HadronPhysicsFTFP_BERT.hh"    // Hadronic interactions
#include "G4IonPhysics.hh"                // Ion physics

class PhysicsList : public G4VModularPhysicsList {
public:
    PhysicsList();
    ~PhysicsList();
};

#endif
