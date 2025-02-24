cmake_minimum_required(VERSION 3.10)

project(BetheSimulation VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

include_directories(${Geant4_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/DetectorConstruction.cc
    src/DetectorMessenger.cc
    src/PrimaryGeneratorAction.cc
    src/PhysicsList.cc
    src/SteppingAction.cc
    src/RunAction.cc
    main.cc
)

add_executable(BetheSimulation ${SOURCES})

target_link_libraries(BetheSimulation ${Geant4_LIBRARIES})

target_compile_definitions(BetheSimulation PRIVATE ${Geant4_DEFINITIONS})

target_compile_options(BetheSimulation PRIVATE
    -W -Wall -pedantic
    -Wno-non-virtual-dtor -Wno-long-long -Wwrite-strings
    -Wpointer-arith -Woverloaded-virtual -Wno-variadic-macros
    -Wshadow -pipe -pthread -ftls-model=initial-exec -std=c++17
)
install(TARGETS BetheSimulation DESTINATION bin)
