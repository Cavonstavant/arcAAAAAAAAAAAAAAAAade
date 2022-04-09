/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** EntryPoint
*/

#include <iostream>
#include "Core.hpp"
extern "C" {
    #include <dlfcn.h>
}


int main(int ac, char **av)
{
    std::vector<std::string> libsPath;
    std::vector<std::shared_ptr<IEntity>> menuEntities;

    if (ac != 2) {
        std::cout << "Usage: ./arcade <graphical_lib> [<garphical_lib>, ...]" << std::endl;
        return (84);
    }
    libsPath.reserve(ac - 1);
    for (int i = 1; i < ac; i++)
        libsPath.emplace_back(av[i]);
    try {
        Core core(libsPath);
        while (core.getState() != Core::State::EXIT) {
            core.update();
            core.draw();
        }
    } catch (std::exception &e) {
        ArcadeEX(e.what(), Logger::HIGH);
        return (84);
    }
    return (0);
}
