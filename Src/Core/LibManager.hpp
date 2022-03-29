/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManager
*/

/// \file LibManager.hpp

#ifndef ARCADE_LIBMANAGER_HPP
#define ARCADE_LIBMANAGER_HPP

#include <string>
#include <map>
#include <vector>
#include "Exception.hpp"

/// \brief Wrapper around the dynamic library CRUD operations
class LibManager {
    public:
        /// \brief Creating a factory without at least a path to a library should be impossible
        LibManager() = delete;

        /// \brief Creating a factory with a path to a library
        /// \param path Path to the game library
        LibManager(std::string &libPath);

        /// \brief Creating a factory with multiple paths to libraries
        /// \param libPaths Paths to the game libraries
        LibManager(std::vector<std::string> libPaths);

        /// \brief A factory should be able to be copied
        LibManager(const LibManager &) = delete;

        /// \brief A factory should not be able to be assigned
        LibManager &operator=(const LibManager &) = delete;

        /// \brief Destructor
        ~LibManager() = default;

        /// \brief Opens a shared library and returns a pointer to the handle
        /// \param libPath Path to the library
        /// \return A pointer to the handle
        /// \note The handle is not closed by the destructor
        /// \warning Not closing the handle will lead to <b>Undefined Behaviour</b>
        /// \throw LibraryException if the library cannot be opened
        void *openLib(std::string &libPath);

        /// \brief Closes a shared library
        /// \param libPath Path to the library
        /// \warning Not using this method after opening a library will lead to <b>Undefined Behaviour</b>
        /// \warning Using this method before opening a library will lead to <b>Undefined Behaviour</b>
        /// \throw LibraryException if the library cannot be closed
        void closeLib(std::string &libPath);

        /// \brief Loads a symbol from a shared library
        /// \param libHandle A pointer to the handle
        /// \param symbolName Name of the symbol to load
        /// \return A pointer to the symbol
        /// \warning Using this method before opening a library will lead to <b>Undefined Behaviour</b>
        /// \throw LibraryException if the symbol cannot be loaded
        void *getSymbol(void *libHandle, std::string &symbolName);

        /// \overload void *getSymbol(void *libHandle, std::string &symbolName)
        void *getSymbol(std::string &libPath, std::string &symbolName);
    private:
        ///\note Map of the libraries' handles represented like so {libPath, libHandle}
        std::map<std::string, void *> _libsHandle;
};


#endif//ARCADE_LIBMANAGER_HPP
