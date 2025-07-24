#include "DetectorConstruction.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "DetectorMessenger.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction(), fSiliconSize(50 * cm) {
    fMessenger = new DetectorMessenger(this); 
}

DetectorConstruction::~DetectorConstruction() {
    delete fMessenger; 
}

void DetectorConstruction::SetSiliconSize(G4double size) {
    fSiliconSize = size;
}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4bool checkOverlaps = true;
    G4NistManager* nist = G4NistManager::Instance();

    G4Material* galactic = nist->FindOrBuildMaterial("G4_Galactic");
    G4Material* silicon = nist->FindOrBuildMaterial("G4_Si");

    G4double worldSize = 100 * cm;  
    G4Box* solidWorld = new G4Box("World", worldSize/2, worldSize/2, worldSize/2);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, galactic, "World");
    G4PVPlacement* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, checkOverlaps);

    G4double siliconThickness = 0.2 * cm;  
    G4double siliconWidth = 1 * cm;
    G4double siliconHeight = 1 * cm;

    G4Box* solidSilicon = new G4Box("Silicon", siliconWidth/2, siliconHeight/2, siliconThickness/2);
    G4LogicalVolume* logicSilicon = new G4LogicalVolume(solidSilicon, silicon, "Silicon");

    new G4PVPlacement(0, G4ThreeVector(0, 0, 5 * cm), logicSilicon, "Silicon", logicWorld, false, 0, checkOverlaps);

    logicWorld->SetVisAttributes(G4VisAttributes::GetInvisible());
    G4VisAttributes* siliconVis = new G4VisAttributes(G4Colour::Green());
    siliconVis->SetVisibility(true);
    siliconVis->SetForceSolid(true);
    logicSilicon->SetVisAttributes(siliconVis);

    return physWorld;
}
