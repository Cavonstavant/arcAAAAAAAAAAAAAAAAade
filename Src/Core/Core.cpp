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
    _mainMenu.init(_entities);
    _libManager.addLibs(libsPath);
    _game = &_mainMenu;
    _graph = _libManager.openGraph(*libsPath.begin());
    _graph->init();
    _mainMenu.start();
    _state = State::MAIN_MENU;
}

void Core::addEntity(const std::shared_ptr<IEntity>& entity)
{
    _entities.push_back(entity);
}

void Core::removeEntity(const std::shared_ptr<IEntity>& entity)
{
    for (auto it = _entities.begin(); it != _entities.end(); ++it) {
        if (*it == entity) {
            _entities.erase(it);
            return;
        }
    }
}

void Core::update() {
    if (_state == State::MAIN_MENU) {
        _mainMenu.update(_entities, _event);
    } else if (_state == State::GAME) {
        _game->update(_entities, _event);
    }
}

#include <iostream>

void Core::draw() {
    for (unsigned long i = 0; i < _entities.size(); i++) {
        std::cout <<
        _graph->drawEntity(*_entities[i], _entities[i]->getPos());
    }
//    for (auto& entity : _entities) {
//        _graph->drawEntity(reinterpret_cast<IEntity &>(entity), entity->getPos());
//    }
}
