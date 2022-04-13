# arcAAAAAAAAAAAAAAAAade

[![Build](https://github.com/Cavonstavant/arcAAAAAAAAAAAAAAAAade/actions/workflows/cmake.yml/badge.svg)](https://github.com/Cavonstavant/arcAAAAAAAAAAAAAAAAade/actions/workflows/cmake.yml) [![GH Pages deployment](https://github.com/Cavonstavant/arcAAAAAAAAAAAAAAAAade/actions/workflows/doc_build.yml/badge.svg)](https://github.com/Cavonstavant/arcAAAAAAAAAAAAAAAAade/actions/workflows/doc_build.yml) [![Mirroring](https://github.com/Cavonstavant/arcAAAAAAAAAAAAAAAAade/actions/workflows/mirroring.yml/badge.svg)](https://github.com/Cavonstavant/arcAAAAAAAAAAAAAAAAade/actions/workflows/mirroring.yml)

## Documentation

The documentation is currently hosted [here](https://cavonstavant.github.io/arcAAAAAAAAAAAAAAAAade/index.html).

> Local documentation can be generated using doxygen with running `doxygen` at the root of the repository. Use `xdg-open doc/build/html/index.html` to open it.

## Build

### Tools

- CMake >= 3.17.0
- g++20

### Building

On Linux:

```bash
    git clone https://github.com/Cavonstavant/arcAAAAAAAAAAAAAAAAade.git
    cd arcAAAAAAAAAAAAAAAAade/
    mkdir build && cd build
    cmake .. -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release
    cmake . --build
    cd ../
```

## How to play

### Keybindings

| Key       | Core Event                                                              |
| --------- | ----------------------------------------------------------------------- |
| 'h' / 'j' | Cycle through the available games, h: backward / j:forward              |
| 'k' / 'l' | Cycle through the available graphic libraries, k: backward / l: forward |
| 'm'       | Switch to the main menu                                                 |
| 'r'       | Reload the current game                                                 |

## Creating and adding your own game and graphical display

---

In order to create your own game and use it inside arcAAAAAAAAAAAAAAAAade, you need to do multiple things:

1. Create a new game folder in the `Src/Games` directory
2. Add a CMakeLists.txt file to the game folder that call the function CMake`create_arcade_game` with multiple arguments:
   1. GAME_NAME: The name of the game, this will also be the name of the created library
   2. SRC: All the game sources files
   3. INCLUDE_DIRS: The `include` path to the game headers files
3. Add the subdirectory to be compiled by adding it to the `Src/Games/CMakeLists.txt` file
4. Create a class that inherits from the `IGame` interface
5. Set its state to 'IGame::GameState::RUNNING' when update is called for the first time
6. Set its state to 'IGame::GameState::STOPPED' when the game is stopped
7. All methods of IGame needs to be implemented

In order to create your own graphical display and use it inside arcAAAAAAAAAAAAAAAAade, you need to do multiple things:

1. Create a new folder in the `Src/GraphicLibs` directory
2. Add a CMakeLists.txt file to the display folder that call the function CMake`create_arcade_display` with multiple arguments:
   1. GRAPHIC_LIB_NAME: The name of the display, this will also be the name of the created library
   2. SRC: All the display sources files
   3. INCLUDE_DIRS: The `include` path to the display headers files
   4. DEPS: The library dependencies (e.g: SDL2::Main SDL2::Image , ${SFML_LIBRARIES} etc..)
3. Add the subdirectory to be compiled by adding it to the `Src/GraphicLibs/CMakeLists.txt` file
4. Create a class that inherits from the `IGraph` interface
5. All methods of IDisplay needs to be implemented

## Misc

---

Other group leader: henri.chauvet@epitech.eu

Epitech repository: https://github.com/EpitechPromo2025/B-OOP-400-NAN-4-1-arcade-constant.vigneron

Mirror repository: https://github.com/Cavonstavant/arcAAAAAAAAAAAAAAAAade

### Graphs

- Graphical representation of the dependencies of the project.
  > By having a graphical representation of the dependencies, we can ensure that the different project parts are actually independent.

![DepsGraph](graph/deps.png)
