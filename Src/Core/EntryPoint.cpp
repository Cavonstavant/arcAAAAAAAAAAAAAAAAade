/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** EntryPoint
*/

#include <iostream>
#include "Core.hpp"
#include "LibManager.hpp"
#include "MainMenu/MainMenu.hpp"

int main(int ac, char **av)
{
    Core core;
    std::vector<std::shared_ptr<IEntity>> entities;

    if (ac != 2) {
        std::cout << "Usage: ./arcade <graphical_lib> [<game_lib>, ...]" << std::endl;
        return (84);
    }
    try {
        MainMenu mainMenu(entities);
        LibManager libManager(av[1]);
    } catch (...) {
        return (84);
    }
    return (0);
}
