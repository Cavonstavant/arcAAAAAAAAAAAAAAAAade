/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#include "Core.hpp"
#include "Button.hpp"
#include "Enemy.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include "TextEntity.hpp"
#include <string>
#include <vector>

Core::Core(std::vector<std::string> libsPath)
{
    _entities.reserve(1000);
    _mainMenu.init(_entities);
    _libManager.addLibs(libsPath);
    _game = &_mainMenu;
    _graph = _libManager.openGraph(*libsPath.begin());
    _graph->init();
    _game->start();
    _state = State::MAIN_MENU;
    _futureGame = "";
    _futureGraph = "";
}

void Core::addEntity(const std::shared_ptr<IEntity> &entity)
{
    _entities.push_back(entity);
}

void Core::removeEntity(const std::shared_ptr<IEntity> &entity)
{
    for (auto it = _entities.begin(); it != _entities.end(); ++it) {
        if (*it == entity) {
            _entities.erase(it);
            return;
        }
    }
}

void Core::update()
{
    Arcade::Evt evt{};
    std::stack<Arcade::Evt> eventBuffer;
    std::stack<Arcade::Evt> eventStack;

    if (_entities.empty())
        return;
    while ((evt = _graph->getInput()).evt_type != Arcade::Evt::NONE) {
        if (evt.evt_type == Arcade::Evt::EvtType::WIN_CLOSE ||
            (evt.evt_type == Arcade::Evt::EvtType::KEY &&
             evt.key.key == '9')) {
            _graph->close();
            _game->close(_entities);
            _state = State::EXIT;
            break;
        } else if (evt.evt_type == Arcade::Evt::EvtType::KEY) {
            _event.push(evt);
            eventBuffer.push(evt);
        }
    }
    while (!eventBuffer.empty()) {
        eventStack.push(eventBuffer.top());
        eventBuffer.pop();
    }
    if (_game->getIsGameOver())
        _state = State::MAIN_MENU;
    if (_state == State::MAIN_MENU) {
        _mainMenu.update(_entities, eventStack);
    } else if (_state == State::GAME) {
        _game->update(_entities, eventStack);
    } else
        _game->close(_entities);
}

void Core::draw()
{
    if (_entities.empty())
        return;
    _graph->clearWindow();
    for (unsigned long i = 0; i < _entities.size(); i++) {
        if (dynamic_cast<TextEntity *>(_entities[i].get())) {
            auto *text = dynamic_cast<TextEntity *>(_entities[i].get());
            _graph->drawText(text->getPos(), text->getText(), text->getColor());
        }
        if (dynamic_cast<Button *>(_entities[i].get())) {
            auto *button = dynamic_cast<Button *>(_entities[i].get());
            _graph->drawRect(button->getPos(), button->getSize().first, button->getSize().second, Color(255, 255, 255, 255));
        }
        if (dynamic_cast<Object *>(_entities[i].get())) {
            auto *wall = dynamic_cast<Object *>(_entities[i].get());
            if (wall->getType() == IEntity::POINT)
                _graph->drawCircle(wall->getPos(), 3, Color(255, 255, 0, 255));
            else if (wall->getType() == IEntity::WALL)
                _graph->drawRect(wall->getPos(), wall->getSize().first, wall->getSize().second, Color(0, 0, 255, 255));
            else
                _graph->drawCircle(wall->getPos(), 8, Color(255, 255, 0, 255));
        }
    }
    for (unsigned long i = 0; i < _entities.size(); i++) {
        if (dynamic_cast<Player *>(_entities[i].get())) {
            auto *player = dynamic_cast<Player *>(_entities[i].get());
            _graph->drawEntity(*_entities[i], player->getPos());
        }
        if (dynamic_cast<Enemy *>(_entities[i].get())) {
            auto *enemy = dynamic_cast<Enemy *>(_entities[i].get());
            _graph->drawEntity(*_entities[i], enemy->getPos());
        }
    }
    if (_game->getScore() >= 0)
        _graph->drawText(std::pair<int, int>{24, 1}, "Score : " + std::to_string(_game->getScore()) + "00", Color(255, 255, 255, 255));
    _graph->displayWindow();
}

void Core::processEvents()
{
    if (_event.empty())
        return;
    if (!_event.empty() && _event.top().evt_type == Arcade::Evt::EvtType::KEY)
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
                currentGameName = _libManager.fetchLibPath(currentGameName);
                _libManager.closeLib(currentGameName);
                _game = _libManager.openGame(currentGameName);
            } catch (...) {
                _event.pop();
                return;
            }
        }
        if (_event.top().key.key == 'm' || _event.top().key.key == 'M') {
            _game->close(_entities);
            _mainMenu.init(_entities);
            _game = &_mainMenu;
            _game->start();
            _event.pop();
            _state = State::MAIN_MENU;
            return;
        }
        if (_event.top().key.key == 'p' || _event.top().key.key == 'P') {
            _state = State::GAME;
            _game->setState(IGame::GameState::PAUSED);
            _event.pop();
            return;
        }
        manageCoreKeyEvents();
    }
}

void Core::setGame(const std::string &lib)
{
    if (!_game->getLibraryName().empty() && _state == State::GAME) {
        _game->close(_entities);
        _libManager.closeLib(_libManager.fetchLibPath(_game->getLibraryName()));
    }
    _game = _libManager.openGame(lib);
    if (!_futureGraph.empty())
        _entities.clear();
    _game->init(_entities);
    _game->start();
}

void Core::setGraph(const std::string &lib)
{
    if (_graph) {
        _graph->close();
        _libManager.closeLib(_libManager.fetchLibPath(_graph->getLibraryName()));
    }
    _graph = _libManager.openGraph(lib);
    _graph->init();
    _graph->clearWindow();
    _graph->displayWindow();
}
