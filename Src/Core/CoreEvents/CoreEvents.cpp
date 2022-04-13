/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** CoreEvent
*/

/// \file Src/Core/CoreEvents.cpp
/// Core event handling for switching between libs

#include "../Core.hpp"

void Core::coreEventSwitchGame()
{
    std::string currentGameName = _game->getLibraryName();

    if (_event.top().key.key == 'h' || _event.top().key.key == 'H') {
        try {
            _game->close(_entities);
            _game = _libManager.cycleGameLibs(currentGameName, false);
            _game->setState(IGame::GameState::RUNNING);
            _game->init(_entities);
            _game->start();
            _event.pop();
            _event.pop();
        } catch (...) {
            _event.pop();
            _event.pop();
            return;
        }
        ArcadeEX("Successfully changed the game library, current game library: " + _game->getLibraryName(), Logger::INFO);
    }
    if (_event.top().key.key == 'j' || _event.top().key.key == 'J') {
        try {
            _game->close(_entities);
            _game = _libManager.cycleGameLibs(currentGameName, true);
            _entities.clear();
            _game->setState(IGame::GameState::RUNNING);
            _game->init(_entities);
            _game->start();
            _event.pop();
            _event.pop();
        } catch (...) {
            _event.pop();
            _event.pop();
            return;
        }
        ArcadeEX("Successfully changed the game library, current game library: " + _game->getLibraryName(), Logger::INFO);
    }
}

void Core::coreEventSwitchGraph()
{
    std::string graphName = _graph->getLibraryName();

    if (_event.top().key.key == 'k' || _event.top().key.key == 'K') {
        try {
            _graph->close();
            _graph = _libManager.cycleGraphLibs(graphName, false);
            _graph->init();
            _event.pop();
            _event.pop();
        } catch (...) {
            _event.pop();
            _event.pop();
            return;
        }
        ArcadeEX("Successfully changed the graph library, current graph library: " + _graph->getLibraryName(), Logger::INFO);
    }
    if (_event.top().key.key == 'l' || _event.top().key.key == 'L') {
        try {
            _graph->close();
            _graph = _libManager.cycleGraphLibs(graphName, true);
            _graph->init();
            _event.pop();
            _event.pop();
        } catch (...) {
            _event.pop();
            _event.pop();
            return;
        }
        ArcadeEX("Successfully changed the graph library, current graph library: " + _graph->getLibraryName(), Logger::INFO);
    }
}

void Core::manageCoreKeyEvents()
{
    if (_event.top().key.key == 'h' || _event.top().key.key == 'H' || _event.top().key.key == 'j' || _event.top().key.key == 'j')
        return coreEventSwitchGame();
    if (_event.top().key.key == 'k' || _event.top().key.key == 'K' || _event.top().key.key == 'l' || _event.top().key.key == 'L')
        return coreEventSwitchGraph();
}
