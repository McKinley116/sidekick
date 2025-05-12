# Drone Management System

## Overview
The Drone Management System is a C++ console application that simulates a tactical drone control environment. The system allows users to manage and control different types of drones (Scout and Fighter) on a randomly generated map with various objects and obstacles.

## Features

### Map System
- Random map generation with customizable dimensions (10x10 minimum)
- Automatic object placement (10% of total map area)
- Grid-based movement system
- Visual map display with coordinate system
- Object type identification (Enemy Drones, Buildings, Blockades)

### Drone Types

#### Scout Drone
- Specialized in reconnaissance
- Can scan and identify objects
- Limited scan charges (10 charges)
- Battery consumption for scanning (10% per scan)
- Rechargeable scanner system

#### Fighter Drone
- Combat-oriented capabilities
- Three missile types:
    - Standard (effective against Enemy Drones)
    - Heavy (effective against Buildings)
    - Burst (effective against Blockades)
- Limited missile capacity (5 missiles)
- Battery consumption for firing (15% per shot)
- Rearmable weapon system

### Common Drone Features
- Unique ID system
- Battery management (100% capacity)
- Movement with battery consumption (5% per unit distance)
- Position tracking
- Recharging capability

### Management Features
- Add new drones with custom names and IDs
- Move drones on the map
- Remove drones from service
- Display detailed drone information
- Sort drones by battery level
- Issue type-specific commands to drones

## Controls
The system operates through a menu-driven interface with the following options:
1. Add new drone
2. Move drone
3. Remove drone
4. Display map
5. Show drone information
6. Issue drone commands
7. Sort drones by battery
8. Exit

## Technical Details
- Language: C++11
- Object-Oriented Design with inheritance
- Dynamic memory management
- Vector-based data structures
- Random number generation for map creation
- Bubble sort implementation for drone sorting

## Legend
- D = Friendly Drone 
- O = Unknown Object 
- E = Enemy Drone 
- B = Building 
- X = Blockade 
- . = Empty

## Battery Usage
- Movement: 5% per unit distance
- Scanning (Scout): 10% per scan
- Firing (Fighter): 15% per shot

## Installation & Running
1. Clone the repository
2. Compile with a C++11 compatible compiler
3. Run the executable

## Requirements
- C++11 compatible compiler
- Standard C++ libraries
- Console with text output support

## Future Enhancements
- Additional drone types
- More complex terrain features
- Multiplayer support
- Advanced pathfinding
- Mission system
- Save/Load functionality

## Authors
Brandon McKinley

## Version
2.0
