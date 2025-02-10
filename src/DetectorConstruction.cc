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
    fMessenger = new DetectorMessenger(this); // Create messenger
}

DetectorConstruction::~DetectorConstruction() {
    delete fMessenger; // Cleanup
}

void DetectorConstruction::SetSiliconSize(G4double size) {
    fSiliconSize = size;
}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4bool checkOverlaps = true;
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* Silicon = nist->FindOrBuildMaterial("G4_Si");

    // World volume
    G4double worldSize = 100 * cm;  // Increase world size for larger detector
    G4Box* solidWorld = new G4Box("World", worldSize/2, worldSize/2, worldSize/2);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4PVPlacement* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, checkOverlaps);

    // Increased Silicon Detector Thickness
    G4double SiliconThickness = 10 * cm;  // Increased from 10cm to 50cm
    G4double SiliconWidth = 10 * cm;
    G4double SiliconHeight = 10 * cm;

    G4Box* solidSilicon = new G4Box("Silicon", SiliconWidth/2, SiliconHeight/2, SiliconThickness/2);
    G4LogicalVolume* logicSilicon = new G4LogicalVolume(solidSilicon, Silicon, "Silicon");

    // Adjust detector placement to avoid overlaps
    new G4PVPlacement(0, G4ThreeVector(0, 0, 25 * cm), logicSilicon, "Silicon", logicWorld, false, 0, checkOverlaps);

    // Set Visualization Attributes
    logicWorld->SetVisAttributes(G4VisAttributes::GetInvisible()); // Hide world
    G4VisAttributes* SiliconVis = new G4VisAttributes(G4Colour::White()); // Green color for visibility
    SiliconVis->SetVisibility(true);
    SiliconVis->SetForceSolid(true);  // Ensures it is solid in visualization
    logicSilicon->SetVisAttributes(SiliconVis);

    // Debugging Output
    //G4cout << "World constructed: " << logicWorld->GetName() << G4endl;
    //G4cout << "Silicon detector constructed: " << logicSilicon->GetName() << G4endl;
    //G4cout << "Silicon detector thickness: " << SiliconThickness / cm << " cm" << G4endl;

    return physWorld;
}
