/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** CoreEvent
*/

/// \file Src/Core/CoreEvents.cpp
/// Core event handling for switching between libs

#include "../Core.hpp"

static void coreEventSwitchGame(const std::string& key, IGame *game, LibManager *libManager)
{
    std::string currentGameName = game->getLibraryName();

    if (key == "h" || key == "H") {
        try {
            libManager->closeLib(currentGameName);
            game = libManager->cycleGameLibs(currentGameName, false);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the game library, current game library: " + game->getLibraryName(), Logger::INFO);
    }
    if (key == "j" || key == "J") {
        try {
            libManager->closeLib(currentGameName);
            game = libManager->cycleGameLibs(currentGameName, true);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the game library, current game library: " + game->getLibraryName(), Logger::INFO);
    }
}

static void coreEventSwitchGraph(const std::string &key, IGraph *graph, LibManager *lib)
{
    std::string graphName = graph->getLibraryName();

    if (key == "k" || key == "K") {
        try {
            lib->closeLib(graphName);
            graph = lib->cycleGraphLibs(graphName, false);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the graph library, current graph library: " + graph->getLibraryName(), Logger::INFO);
    }
    if (key == "l" || key == "L") {
        try {
            lib->closeLib(graphName);
            graph = lib->cycleGraphLibs(graphName, true);
        } catch (...) {
            return;
        }
        ArcadeEX("Successfully changed the graph library, current graph library: " + graph->getLibraryName(), Logger::INFO);
    }
}

void manageCoreKeyEvents(std::string &key , IGame *game, IGraph *graph, LibManager *lib)
{
    if (key == "h" || key == "H" || key == "j" || key == "j")
        return coreEventSwitchGame(key, game, lib);
    if (key == "k" || key == "K" || key == "l" || key == "L")
        return coreEventSwitchGraph(key, graph, lib);
}