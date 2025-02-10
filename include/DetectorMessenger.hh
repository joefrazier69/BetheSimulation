#ifndef DetectorMessenger_h
#define DetectorMessenger_h 1

#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "globals.hh"

class DetectorConstruction;

class DetectorMessenger : public G4UImessenger {
public:
    DetectorMessenger(DetectorConstruction* detector);
    virtual ~DetectorMessenger();

    virtual void SetNewValue(G4UIcommand* command, G4String newValue);

private:
    DetectorConstruction* fDetector;
    G4UIcmdWithADoubleAndUnit* fSiliconSizeCmd;
};

#endif
