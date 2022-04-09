#include "IGame.hpp"
#include "Nibbler.hpp"
#include <iostream>
#include <vector>

namespace Arcade {
    static IGame *GAME_INSTANCE = nullptr;

    extern "C" IGame *getGameInstance()
    {
        return GAME_INSTANCE;
    }

    [[gnu::constructor]] void libConstruct()
    {
        GAME_INSTANCE = new Nibbler();
        std::cout << "lib loaded" << std::endl;
    }

    [[gnu::destructor]] void libDestruct()
    {
        delete GAME_INSTANCE;
        std::cout << " lib unloaded" << std::endl;
    }
}// namespace Arcade