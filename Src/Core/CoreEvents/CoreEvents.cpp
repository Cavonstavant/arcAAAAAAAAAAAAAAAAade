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
    currentGameName = _libManager.fetchLibPath(currentGameName);

    if (_event.top().key.key == 'h' || _event.top().key.key == 'H') {
        try {
            _libManager.closeLib(currentGameName);
            _game = _libManager.cycleGameLibs(currentGameName, false);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the game library, current game library: " + _game->getLibraryName(), Logger::INFO);
    }
    if (_event.top().key.key == 'j' || _event.top().key.key == 'J') {
        try {
            _libManager.closeLib(currentGameName);
            _game = _libManager.cycleGameLibs(currentGameName, true);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the game library, current game library: " + _game->getLibraryName(), Logger::INFO);
    }
}

void Core::coreEventSwitchGraph()
{
    std::string graphName = _graph->getLibraryName();
    graphName = _libManager.fetchLibPath(graphName);

    if (_event.top().key.key == 'k' || _event.top().key.key == 'K') {
        try {
            _graph->close();
            _libManager.closeLib(graphName);
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
            _libManager.closeLib(graphName);
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
