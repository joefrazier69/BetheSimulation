#include "G4RunManager.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "PhysicsList.hh"
#include "SteppingAction.hh"
#include "RunAction.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"  // Include the UI manager header
#include "globals.hh" 
int main(int argc, char** argv) {
    // Create the run manager
    G4RunManager* runManager = new G4RunManager;

    // Set mandatory initialization classes
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsList());

    // Set user action classes
    SteppingAction* steppingAction = new SteppingAction();
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(new RunAction(steppingAction));
    runManager->SetUserAction(steppingAction);

    // Initialize the run manager
    runManager->Initialize();

    // Initialize visualization
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // Initialize UI session (for interactive mode)
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    // Get the UI manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/run/verbose 0");
    UImanager->ApplyCommand("/event/verbose 0");
    UImanager->ApplyCommand("/tracking/verbose 0");
    // Apply visualization commands
    UImanager->ApplyCommand("/vis/open OGL");  // Open the OpenGL visualization window
    UImanager->ApplyCommand("/vis/drawVolume");  // Draw the geometry (silicon block)
    UImanager->ApplyCommand("/vis/viewer/set/viewpointThetaPhi 90 0");  // Set the viewpoint
    UImanager->ApplyCommand("/vis/scene/add/trajectories");  // Add particle trajectories
    UImanager->ApplyCommand("/vis/scene/add/hits");  // Add hits (energy deposition points)
    UImanager->ApplyCommand("/vis/viewer/refresh");  // Refresh the visualization window
    UImanager->ApplyCommand("/vis/viewer/zoomTo 2");  // Zoom in on the geometry

    UImanager->ApplyCommand("/detector/setSize 10 cm");  // User command to modify detector
    // Start the simulation
    runManager->BeamOn(100); // Simulate 10 protons

    // Start UI session (interactive mode)
    ui->SessionStart();

    // Clean up
    delete ui;
    delete visManager;
    delete runManager;

    return 0;
}