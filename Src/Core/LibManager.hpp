/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManager
*/

/// \file LibManager.hpp

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

        /// \brief Creating a library manager with multiple paths to libraries
        /// \param libPaths Paths to the game libraries
        LibManager(const std::vector<std::string> &libPaths);

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
        void addLibs(std::vector<std::string> &libPaths);

        /// \brief Opens a shared library, calls it's lib entrypoint and returns a pointer to a game instance
        /// \param libPath Path to the library
        /// \return A pointer to a game instance
        IGame *openGame(const std::string &libPath);

        /// \brief Opens a shared library, calls it's lib entrypoint and returns a pointer to a graph instance
        /// \param libPath Path to the library
        /// \return A pointer to a graph instance
        IGraph *openGraph(const std::string &libPath);

        /// \brief Closes a shared library
        /// \param libPath Path to the library
        /// \warning Not using this method after opening a library will lead to <b>Undefined Behaviour</b>
        /// \warning Using this method before opening a library will lead to <b>Undefined Behaviour</b>
        /// \throw LibraryException if the library cannot be closed
        void closeLib(const std::string &libPath);

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

        /// \brief Add a game to the list of available games
        /// \param gamePath the game path to add
        /// \note This method is only used to differentiate between games and graph libraries, it does not actually add the game to the lib manager
        /// \warning Using this method without using addLibs() will lead to <b>Undefined Behaviour</b>
        inline void addGame(std::string &gamePath)
        {
            _gameLibsName.push_back(gamePath);
        }

        /// \brief Add a graph to the list of available graphs
        /// \param graphPath the graph path to add
        /// \note This method is only used to differentiate between games and graph libraries, it does not actually add the graph to the lib manager
        /// \warning Using this method without using addLibs() will lead to <b>Undefined Behaviour</b>
        inline void addGraph(std::string &graphPath)
        {
            _graphLibsName.push_back(graphPath);
        }

        /// \brief will fetch the lib path given it's name
        /// \param libName the name of the lib
        /// \return the lib path
        ///  \note This is used to translate getLibraryName() to the stored lib path
        [[nodiscard]] std::string fetchLibPath(std::string name);

    private:
        /// \brief private enum to represent the type of the library type
        /// Used internally
        enum class libType {
            GAME,
            GRAPH
        };
        ///\brief Map of the libraries' handles represented like so {libPath, libHandle}
        std::map<std::string, void *> _libsHandle;

        /// \brief internal representation of the a game library
        std::vector<std::string> _gameLibsName;

        /// \brief internal representation of the a graph library
        std::vector<std::string> _graphLibsName;
};


#endif//ARCADE_LIBMANAGER_HPP
