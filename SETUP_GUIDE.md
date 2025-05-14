# Stronghold Game Setup Guide

## Prerequisites

### Windows
1. Install Visual Studio 2019 or later
   - Download from: https://visualstudio.microsoft.com/downloads/
   - During installation, select "Desktop development with C++"
   - Make sure to include CMake support

2. Install CMake
   - Download from: https://cmake.org/download/
   - Choose the Windows x64 Installer
   - During installation, select "Add CMake to the system PATH"

### Linux
1. Install required packages:
```bash
sudo apt update
sudo apt install build-essential cmake g++
```

## Building the Game

### Windows
1. Open Command Prompt or PowerShell
2. Navigate to the game directory:
```cmd
cd path\to\Stronghold
```
3. Create and enter build directory:
```cmd
mkdir build
cd build
```
4. Generate build files:
```cmd
cmake ..
```
5. Build the project:
```cmd
cmake --build . --config Release
```
6. The executable will be in `build\Release\stronghold.exe`

### Linux
1. Open Terminal
2. Navigate to the game directory:
```bash
cd path/to/Stronghold
```
3. Create and enter build directory:
```bash
mkdir -p build
cd build
```
4. Generate build files:
```bash
cmake ..
```
5. Build the project:
```bash
make
```
6. The executable will be in `build/stronghold`

## Running the Game

### Windows
1. Open Command Prompt or PowerShell
2. Navigate to the build directory:
```cmd
cd path\to\Stronghold\build\Release
```
3. Run the game:
```cmd
.\stronghold.exe
```

### Linux
1. Open Terminal
2. Navigate to the build directory:
```bash
cd path/to/Stronghold/build
```
3. Run the game:
```bash
./stronghold
```

## Troubleshooting

### Common Windows Issues
1. "CMake not found"
   - Ensure CMake is installed and added to PATH
   - Restart Command Prompt/PowerShell

2. "Visual Studio not found"
   - Ensure Visual Studio is installed with C++ support
   - Run `Developer Command Prompt for VS` instead

3. "Build failed"
   - Check if all source files are present
   - Ensure you have write permissions in the directory

### Common Linux Issues
1. "CMake not found"
   - Run: `sudo apt install cmake`

2. "Compiler not found"
   - Run: `sudo apt install build-essential`

3. "Permission denied"
   - Run: `chmod +x stronghold`

## Project Structure
```
Stronghold/
├── CMakeLists.txt
├── Stronghold.h
├── main.cpp
├── GameEngine.cpp
├── Kingdom.cpp
├── Map.cpp
├── Conflict.cpp
├── Market.cpp
├── Communication.cpp
├── Alliance.cpp
├── Event.cpp
├── Bank.cpp
├── Economy.cpp
├── Leader.cpp
├── Military.cpp
├── Population.cpp
├── ResourceContainer.cpp
└── build/
    └── stronghold (or stronghold.exe)
```

## Development Tools
- Visual Studio Code (recommended)
- CLion
- Visual Studio
- Any C++ IDE with CMake support

## Version Control
- Git is recommended for version control
- Initialize repository:
```bash
git init
git add .
git commit -m "Initial commit"
```

## Additional Resources
- C++ Documentation: https://en.cppreference.com/
- CMake Documentation: https://cmake.org/documentation/
- Visual Studio Documentation: https://docs.microsoft.com/en-us/visualstudio/ 