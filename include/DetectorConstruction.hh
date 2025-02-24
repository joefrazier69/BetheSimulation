#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Material.hh"

#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

#include "G4VisAttributes.hh"
#include "G4Color.hh"
#include "G4SDManager.hh"

class G4VPhysicalVolume;
class DetectorMessenger;  

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    DetectorConstruction();
    virtual ~DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    void SetSiliconSize(G4double size);

private:
    G4double fSiliconSize;
    DetectorMessenger* fMessenger;  
};

#endif
