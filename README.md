# Stronghold Game

A medieval kingdom management simulation game written in C++.

## Description

Stronghold is a text-based strategy game where players manage a medieval kingdom. The game features:
- Resource management (food, wood, stone, iron)
- Population management with different social classes
- Military system with combat mechanics
- Economic system with tax management
- Diplomatic actions including alliances and trade
- Random events that affect gameplay

## Features

- Multiple social classes (Peasants, Merchants, Nobles)
- Resource management system
- Military recruitment and combat
- Economic policies and tax management
- Diplomatic actions (alliances, trade, messages)
- Random events (famine, disease, war)
- Save/Load game functionality

## Requirements

### Windows
- Visual Studio 2019 or later
- CMake 3.10 or later

### Linux
- GCC/G++ compiler
- CMake 3.10 or later
- Build essentials

## Installation

1. Clone the repository:
```bash
git clone https://github.com/sureshbarach2001/Strong-Hold-Game.git
cd stronghold
```

2. Build the project:
```bash
# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build the project
# On Windows:
cmake --build . --config Release
# On Linux:
make
```

3. Run the game:
```bash
# Windows
.\build\Release\stronghold.exe

# Linux
./build/stronghold
```

## How to Play

1. Start the game
2. Choose your kingdom
3. Manage resources and population
4. Make strategic decisions
5. Interact with other kingdoms
6. Survive and prosper

For detailed gameplay instructions, see [GAME_MANUAL.md](GAME_MANUAL.md)

## Project Structure

```
Stronghold/
├── CMakeLists.txt          # Build configuration
├── Stronghold.h           # Main header file
├── main.cpp              # Entry point
├── GameEngine.cpp        # Game engine implementation
├── Kingdom.cpp           # Kingdom management
├── Map.cpp              # Map system
├── Conflict.cpp         # Combat system
├── Market.cpp           # Trading system
├── Communication.cpp    # Messaging system
├── Alliance.cpp         # Alliance management
├── Event.cpp            # Random events
├── Bank.cpp             # Economic system
├── Economy.cpp          # Economy management
├── Leader.cpp           # Leadership system
├── Military.cpp         # Military management
├── Population.cpp       # Population system
├── ResourceContainer.cpp # Resource management
├── GAME_MANUAL.md       # Detailed game manual
├── SETUP_GUIDE.md       # Setup instructions
└── README.md            # This file
```

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to all contributors
- Inspired by medieval strategy games
- Built with C++ and CMake

## Contact

Suresh Kumar - [@Portfolio](https://sureshkumar2001.vercel.app)
Project Link: [https://github.com/sureshbarach2001/Strong-Hold-Game.git](https://github.com/sureshbarach2001/Strong-Hold-Game.git)) 
