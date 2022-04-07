/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** EntryPoint
*/

#include <iostream>
#include "Core.hpp"


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
        libsPath.push_back(av[i]);
    try {
        Core core(libsPath);
        // LibManager libManager(libsPath);
        // IGraph *graph = libManager.openGraph(libsPath.begin()->c_str());

    } catch (...) {
        return (84);
    }
    return (0);
}
