# Drone Management System

## Overview
Sidekick is a C++ console application that simulates a tactical drone control environment. The system allows users to manage and control different types of drones (Scout and Fighter) on a randomly generated map with various objects and obstacles.

## Table of Contents
1. [Architecture Overview](#architecture-overview)
2. [Class Documentation](#class-documentation)
3. [System Components](#system-components)
4. [Implementation Details](#implementation-details)
5. [API Reference](#api-reference)
6. [User Guide](#user-guide)

## Architecture Overview

### Design Pattern
The system follows an object-oriented design with inheritance hierarchy:
- Base class: `drone`
- Derived classes: `scout` and `fighter`
- Support classes: `map` and `user_menu`

### Core Components
1. **Map System**: Manages the game grid and object placement
2. **Drone Management**: Handles drone creation, movement, and actions
3. **User Interface**: Menu-driven command system
4. **Object Management**: Handles various objects and their interactions

## Class Documentation

### Drone Base Class (`drone.h`)
Abstract base class for all drone types.cpp class drone
#### Key Methods:
- `move(int x, int y)`: Moves drone with battery consumption
- `charge_battery()`: Restores battery to 100%
- `decrease_battery(int amount)`: Reduces battery by specified amount

### Scout Class (`scout.h`)
Specialized drone for reconnaissance.
#### Key Features:
- Scan charges: 10 maximum
- Vision range: 6 units
- Battery cost per scan: 10%

### Fighter Class (`fighter.h`)
Combat-oriented drone.
#### Key Features:
- Missile capacity: 5 missiles
- Vision range: 3 units
- Battery cost per shot: 15%
- Three missile types: Standard, Heavy, Burst

### Map Class (`map.h`)
Manages game environment and objects.
#### Key Features:
- Dynamic grid system
- Object type management
- Drone tracking
- Collision detection

## System Components

### Grid System
- Dimensions: 10x10 minimum, 40x40 maximum
- Cell Types: Empty, Drone, Object
- Object Types: Enemy Drone, Building, Blockade

### Battery Management
- Initial charge: 100%
- Movement cost: 5% per unit distance
- Action costs:
  - Scanning: 10%
  - Firing: 15%

### Resource Management
#### Scout Drone:
- Scanner charges: 10 maximum
- Recharge capability

#### Fighter Drone:
- Missile capacity: 5 maximum
- Rearm capability
- Missile effectiveness varies by target type

## Implementation Details

### Memory Management
- Dynamic allocation for drones
- Vector-based storage for map grid
- Proper cleanup on drone removal

### Algorithm Implementations
- Bubble Sort for drone battery sorting
- Manhattan distance for movement calculations
- Random number generation for map creation

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
