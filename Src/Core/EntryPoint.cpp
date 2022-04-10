/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** EntryPoint
*/

#include "Core.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>
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
    for (int i = 1; i < ac; i++) {
        while (av[i][0] == '.' || av[i][0] == '/')
            av[i]++;
        libsPath.emplace_back(std::filesystem::absolute(std::filesystem::path(av[i])));
    }
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
                    core.setFutureGame(libPath);
                core.popEvent();
            }
            if (!core.getFutureGame().empty() && !core.getFutureGraph().empty()) {
                std::string currentGraph = core.getGraph()->getLibraryName();
                std::transform(currentGraph.begin(), currentGraph.end(), currentGraph.begin(), ::tolower);
                if (currentGraph.find(core.getFutureGraph()) == std::string::npos) {
                    core.setGraph(core.getFutureGraph());
                }
                core.setGame(core.getFutureGame());
                std::string newFutureGame;
                std::string newFutureGraph;
                core.setFutureGame(newFutureGame);
                core.setFutureGraph(newFutureGraph);
            }
            if (core.getGraph() != nullptr && core.getGame() != nullptr)
                core.draw();
            if (core.getGraph() != nullptr && core.getGame() != nullptr)
                core.processEvents();
        }
    } catch (std::exception &e) {
        ArcadeEX(e.what(), Logger::CRITICAL);
        return (84);
    }
    return (0);
}
