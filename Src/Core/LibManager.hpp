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
        /// \brief Creating a library manager without at least a path to a library should be impossible
        LibManager();

        /// \brief Creating a library manager with multiple paths to libraries
        /// \param libPaths Paths to the game libraries
        LibManager(std::vector<std::string> libPaths);

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
        void addLib(std::string libPath);

        /// \brief Opens a shared library, calls it's lib entrypoint and returns a pointer to a game instance
        /// \param libPath Path to the library
        /// \return A pointer to a game instance
        IGame *openGame(std::string libPath);

        /// \brief Opens a shared library, calls it's lib entrypoint and returns a pointer to a graph instance
        /// \param libPath Path to the library
        /// \return A pointer to a graph instance
        IGraph *openGraph(std::string libPath);

        /// \brief Add a lib to be managed by the library manager
        /// \param libPaths Paths to the libraries
        void addLib(std::vector<std::string> libPaths);

        /// \brief Closes a shared library
        /// \param libPath Path to the library
        /// \warning Not using this method after opening a library will lead to <b>Undefined Behaviour</b>
        /// \warning Using this method before opening a library will lead to <b>Undefined Behaviour</b>
        /// \throw LibraryException if the library cannot be closed
        void closeLib(std::string libPath);

    private:
        /// \brief Loads all of the game libraries present inside the lib.conf file inside the _libsHandle span
        /// \note This method will read inside the lib.conf file at root and will seek for [libPath] (default value: "./lib")
        void loadGameLibs(void);

        ///\note Map of the libraries' handles represented like so {libPath, libHandle}
        std::map<std::string, void *> _libsHandle;

        /// \brief Opens a shared library and returns a pointer to the handle
        /// \param libPath Path to the library
        /// \return A pointer to the handle
        /// \note The handle is not closed by the destructor
        /// \warning Not closing the handle will lead to <b>Undefined Behaviour</b>
        /// \throw LibraryException if the library cannot be opened
        void *openLib(std::string libPath);
};


#endif//ARCADE_LIBMANAGER_HPP
