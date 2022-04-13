/*
** EPITECH PROJECT, 2022
** entrypoint.cpp.c
** File description:
** Created by hjulien,
*/

#include "IGame.hpp"
#include "Pacman.hpp"
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
        GAME_INSTANCE = new Pacman();
        std::cout << "lib loaded" << std::endl;
    }

    [[gnu::destructor]] void libDestruct()
    {
        delete GAME_INSTANCE;
    }
}// namespace Arcade
