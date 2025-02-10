# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(BetheSimulation VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Geant4 package
find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})
# Include directories
include_directories(${Geant4_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/DetectorConstruction.cc
    src/DetectorMessenger.cc
    src/PrimaryGeneratorAction.cc
    src/PhysicsList.cc
    src/SteppingAction.cc
    src/RunAction.cc
    main.cc
)

# Add executable
add_executable(BetheSimulation ${SOURCES})

# Link Geant4 libraries
target_link_libraries(BetheSimulation ${Geant4_LIBRARIES})

# Add Geant4 compile definitions and flags
target_compile_definitions(BetheSimulation PRIVATE ${Geant4_DEFINITIONS})

# Manually set compile options (instead of using Geant4_CXX_FLAGS)
target_compile_options(BetheSimulation PRIVATE
    -W -Wall -pedantic
    -Wno-non-virtual-dtor -Wno-long-long -Wwrite-strings
    -Wpointer-arith -Woverloaded-virtual -Wno-variadic-macros
    -Wshadow -pipe -pthread -ftls-model=initial-exec -std=c++17
)

# Install target (optional)
install(TARGETS BetheSimulation DESTINATION bin)