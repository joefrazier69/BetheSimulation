#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UImanager.hh"
#include "G4SystemOfUnits.hh"

DetectorMessenger::DetectorMessenger(DetectorConstruction* detector) : fDetector(detector) {
    
    fSiliconSizeCmd = new G4UIcmdWithADoubleAndUnit("/detector/setSize", this);
    fSiliconSizeCmd->SetGuidance("Set the size of the silicon detector.");
    fSiliconSizeCmd->SetParameterName("Size", false);
    fSiliconSizeCmd->SetUnitCategory("Length");
    fSiliconSizeCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
}

DetectorMessenger::~DetectorMessenger() {
    delete fSiliconSizeCmd;
}


void DetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue) {
    if (command == fSiliconSizeCmd) {
        fDetector->SetSiliconSize(fSiliconSizeCmd->GetNewDoubleValue(newValue));
    }
}
