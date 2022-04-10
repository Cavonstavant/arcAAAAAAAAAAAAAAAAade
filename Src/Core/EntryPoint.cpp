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
        std::cout << "Usage: ./arcade <graphical_lib>" << std::endl;
        return (84);
    }
    libsPath.reserve(ac - 1);
    for (int i = 1; i < ac; i++)
        libsPath.emplace_back(av[i]);
    try {
        Core core(libsPath);
        while (core.getState() != Core::State::EXIT) {
            try {
                core.update();
            } catch (ArcadeException &e) {
                std::string libInfo = std::string(e.what());
                std::string libPath = libInfo.substr(libInfo.find(';') + 1);
                if (libInfo.substr(0, libInfo.find(';')) == "Graph")
                    core.setFutureGraph(libPath);
                else
                    core.setGame(libPath);
                core.popEvent();
            }
            if (core.getGame() == nullptr && core.getGraph() == nullptr && !core.getFutureGraph().empty() && !core.getFutureGame().empty()) {
                core.setGame(core.getFutureGame());
                core.setGraph(core.getFutureGraph());
            }
            if (core.getGraph() != nullptr || core.getGame() != nullptr)
                core.draw();
            if (core.getGraph() != nullptr || core.getGame() != nullptr)
                core.processEvents();
        }
    } catch (...) {
        return (84);
    }
    return (0);
}
