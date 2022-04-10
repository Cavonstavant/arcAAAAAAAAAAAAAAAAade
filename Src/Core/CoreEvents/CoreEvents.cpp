/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** CoreEvent
*/

/// \file Src/Core/CoreEvents.cpp
/// Core event handling for switching between libs

#include "../Core.hpp"

void Core::coreEventSwitchGame(const std::string &key)
{
    std::string currentGameName = _game->getLibraryName();

    if (key == "h" || key == "H") {
        try {
            _libManager.closeLib(currentGameName);
            _game = _libManager.cycleGameLibs(currentGameName, false);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the game library, current game library: " + _game->getLibraryName(), Logger::INFO);
    }
    if (key == "j" || key == "J") {
        try {
            _libManager.closeLib(currentGameName);
            _game = _libManager.cycleGameLibs(currentGameName, true);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the game library, current game library: " + _game->getLibraryName(), Logger::INFO);
    }
}

void Core::coreEventSwitchGraph(const std::string &key)
{
    std::string graphName = _graph->getLibraryName();

    if (key == "k" || key == "K") {
        try {
            _libManager.closeLib(graphName);
            _graph = _libManager.cycleGraphLibs(graphName, false);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the graph library, current graph library: " + _graph->getLibraryName(), Logger::INFO);
    }
    if (key == "l" || key == "L") {
        try {
            _libManager.closeLib(graphName);
            _graph = _libManager.cycleGraphLibs(graphName, true);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the graph library, current graph library: " + _graph->getLibraryName(), Logger::INFO);
    }
}

void Core::manageCoreKeyEvents(std::string &key)
{
    if (key == "h" || key == "H" || key == "j" || key == "j")
        return coreEventSwitchGame(key);
    if (key == "k" || key == "K" || key == "l" || key == "L")
        return coreEventSwitchGraph(key);
}
