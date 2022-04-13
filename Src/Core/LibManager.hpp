/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManager
*/

/// \file Src/Core/LibManager.hpp

#ifndef ARCADE_LIBMANAGER_HPP
#define ARCADE_LIBMANAGER_HPP

#include "Exception.hpp"
#include "IGame.hpp"
#include "IGraph.hpp"
#include <map>
#include <string>
#include <vector>

/// \brief Wrapper around the dynamic library CRUD operations
class LibManager {
public:
    /// \brief Creating a library manager without at least a path to a library should be possible
    LibManager() = default;

    /// \brief A library manager should be able to be copied
    LibManager(const LibManager &) = delete;

    /// \brief A library manager should not be able to be assigned
    LibManager &operator=(const LibManager &) = delete;

    /// \brief Destructor
    ~LibManager() = default;

    /// \brief Add a lib to be managed by the library manager
    /// \param libPath Path to the library
    /// \throw FileNotFoundException if the library cannot be found
    /// \throw LibraryException if the library cannot be opened
    void addLibs();

    /// \brief Opens a shared library, calls it's lib entrypoint and returns a pointer to a game instance
    /// \param libPath Path to the library
    /// \return A pointer to a game instance
    IGame *openGame(const std::string &libPath);

    /// \brief Opens a shared library, calls it's lib entrypoint and returns a pointer to a graph instance
    /// \param libPath Path to the library
    /// \return A pointer to a graph instance
    IGraph *openGraph(const std::string &libPath);

    /// \brief Closes all shared libraries
    void closeAllLibs();

    /// \brief Cycle through available game libraries in the library manager and return the next/previous one
    /// (ordered by the order of the libPaths vector)
    /// \param currentLib The current game library path
    /// \param direction The direction to cycle through the game libraries. <b>true</b> for next, <b>false</b> for previous
    /// \return A pointer to a game new instance
    /// \note This closes the previous library and opens the next one
    /// \throw LibraryException if the library cannot be opened
    IGame *cycleGameLibs(std::string &currentLib, bool direction = true);

    /// \brief Cycle through available graph libraries in the library manager and return the next/previous one
    /// (ordered by the order of the libPaths vector)
    /// \param currentLib The current graph library path
    /// \param direction The direction to cycle through the graph libraries. <b>true</b> for next, <b>false</b> for previous
    /// \return A pointer to a game new instance
    /// \note This closes the previous library and opens the next one
    /// \throw LibraryException if the library cannot be opened
    IGraph *cycleGraphLibs(std::string &currentLib, bool direction = true);


private:

    /// \brief collection of the game libs paths
    std::vector<std::string> _gameLibsPaths;

    /// \brief internal representation of the a game library
    std::vector<IGame*> _gameLibsInstances;

    /// \brief collection of the graph libs paths
    std::vector<std::string> _graphLibsPaths;

    /// \brief internal representation of the a graph library
    std::vector<IGraph*> _graphLibsInstances;
};


#endif//ARCADE_LIBMANAGER_HPP
