/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#include <vector>
#include <string>
#include "Core.hpp"
#include "TextEntity.hpp"
#include "Button.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Enemy.hpp"
#include <iostream>

Core::Core(std::vector<std::string> libsPath)
{
    _mainMenu.init(_entities);
    _libManager.addLibs(libsPath);
   _game = &_mainMenu;
    // _game = _libManager.openGame("lib/arcade_nibbler.so");
    // _game->init(_entities);
    _graph = _libManager.openGraph(*libsPath.begin());
    _graph->init();
    _game->start();
    /*_mainMenu.start();*/
    // _state = State::GAME;
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
    } else
        _game->close(_entities);
}

void Core::draw() {
    _graph->clearWindow();
    for (unsigned long i = 0; i < _entities.size(); i++) {
        if (dynamic_cast<TextEntity*>(_entities[i].get())) {
            auto *text = dynamic_cast<TextEntity*>(_entities[i].get());
            _graph->drawText(text->getPos(), text->getText());
        }
        if (dynamic_cast<Button*>(_entities[i].get())) {
            auto *button = dynamic_cast<Button*>(_entities[i].get());
            _graph->drawRect(button->getPos(), button->getSize().first, button->getSize().second, Color(255, 255, 255, 255));
        }
        if (dynamic_cast<Object*>(_entities[i].get())) {
            auto *wall = dynamic_cast<Object*>(_entities[i].get());
            if (wall->getType() == IEntity::POINT)
                _graph->drawCircle(wall->getPos(), 3, Color(255, 255, 0, 255));
            else if (wall->getType() == IEntity::WALL)
                _graph->drawRect(wall->getPos(), wall->getSize().first, wall->getSize().second, Color(0, 0, 255, 255));
            else
                _graph->drawCircle(wall->getPos(), 8, Color(255, 255, 0, 255));
        }
        if (dynamic_cast<Player*>(_entities[i].get())) {
            auto *player = dynamic_cast<Player*>(_entities[i].get());
            _graph->drawEntity(*_entities[i], player->getPos());
        }
    }
    _graph->displayWindow();
}

void Core::processEvents() {
    if (_event.empty())
        return;
    if (_event.top().evt_type == Arcade::Evt::WIN_CLOSE) {
        if (_state == State::MAIN_MENU) {
            _mainMenu.close(_entities);
            _state = State::EXIT;
            _event.pop();
            return;
        }
        if (_state == State::GAME) {
            _game->setState(IGame::GameState::STOPPED);
            _state = State::MAIN_MENU;
            _game = &_mainMenu;
            _event.pop();
            return;
        }
    }
    if (_game->getState() == IGame::GameState::STOPPED) {
        _state = State::MAIN_MENU;
        _game = &_mainMenu;
        _event.pop();
        return;
    }
    if (_event.top().evt_type == Arcade::Evt::KEY) {
        if (_event.top().key.key == 'r' || _event.top().key.key == 'R') {
            try {
                std::string currentGameName = _game->getLibraryName();
                _libManager.closeLib(currentGameName);
                _game = _libManager.openGame(currentGameName);
            } catch (...) {
                _event.pop();
                return;
            }
        }
        if (_event.top().key.key == 'm' || _event.top().key.key == 'M') {
            _state = State::MAIN_MENU;
            _game = &_mainMenu;
            _event.pop();
            return;
        }
        if (_event.top().key.key == 'p' || _event.top().key.key == 'P') {
            _state = State::GAME;
            _game->setState(IGame::GameState::PAUSED);
            _event.pop();
            return;
        }
        manageCoreKeyEvents(reinterpret_cast<std::string &>(_event.top().key.key), _game, _graph, &_libManager);
    }
}