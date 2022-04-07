/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#include <vector>
#include <string>
#include "Core.hpp"
#include <iostream>

Core::Core(std::vector<std::string> libsPath)
{
    std::vector<std::shared_ptr<IEntity>> _ett; //< Test vector of entities
    _mainMenu.init(_ett);
    std::cout << "Lib size: " << libsPath.size() << std::endl;
    _libManager.addLib(libsPath);
    _game = &_mainMenu;
    _graph = _libManager.openGraph(libsPath.begin()->c_str());
    _mainMenu.start();
}

void Core::addEntity(std::shared_ptr<IEntity> entity)
{
    _entities.push_back(entity);
}

void Core::removeEntity(std::shared_ptr<IEntity> entity)
{
    _entities.erase(std::remove(_entities.begin(), _entities.end(), entity), _entities.end());
}