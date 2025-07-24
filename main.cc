#include "G4RunManager.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "PhysicsList.hh"
#include "SteppingAction.hh"
#include "RunAction.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"  
#include "globals.hh" 
int main(int argc, char** argv) {
    
    G4RunManager* runManager = new G4RunManager;

    
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsList());

    
    SteppingAction* steppingAction = new SteppingAction();
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(new RunAction(steppingAction));
    runManager->SetUserAction(steppingAction);

    
    runManager->Initialize();

    
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);


    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/run/verbose 0");
    UImanager->ApplyCommand("/event/verbose 0");
    UImanager->ApplyCommand("/tracking/verbose 0");

    UImanager->ApplyCommand("/vis/open OGL");  
    UImanager->ApplyCommand("/vis/drawVolume");  
    UImanager->ApplyCommand("/vis/viewer/set/viewpointThetaPhi 90 0");   
    UImanager->ApplyCommand("/vis/scene/add/trajectories");   
    UImanager->ApplyCommand("/vis/scene/add/hits");    
    UImanager->ApplyCommand("/vis/viewer/refresh");   
    UImanager->ApplyCommand("/vis/viewer/zoomTo 2");   

    UImanager->ApplyCommand("/detector/setSize 10 cm");   

    runManager->BeamOn(1e3);  


    ui->SessionStart();


    delete ui;
    delete visManager;
    delete runManager;

    return 0;
}
