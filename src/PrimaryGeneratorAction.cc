#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Proton.hh"
#include "G4SystemOfUnits.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    fParticleGun = new G4ParticleGun(1);
    fParticleGun->SetParticleDefinition(G4Proton::ProtonDefinition());
    fParticleGun->SetParticleEnergy(30 * MeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0, 0, -0.4 * cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
