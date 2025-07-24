#ifndef PHYSICSLIST_HH
#define PHYSICSLIST_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics_option3.hh"  // electromagnetic physics
#include "G4HadronPhysicsFTFP_BERT.hh"    // hadronic interactions
#include "G4IonPhysics.hh"                // ion physics

class PhysicsList : public G4VModularPhysicsList {
public:
    PhysicsList();
    ~PhysicsList();
};

#endif
