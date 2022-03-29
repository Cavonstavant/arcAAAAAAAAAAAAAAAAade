/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManager
*/

#include "LibManager.hpp"
#include "Exception.hpp"
extern "C" {
    #include <dlfcn.h>
}

LibManager::LibManager(std::string &libPath)
{
    _libsHandle.emplace(libPath, nullptr);
}

LibManager::LibManager(std::span<std::string> libPaths)
{
    for (auto &libPath : libPaths) {
        _libsHandle.emplace(libPath, nullptr);
    }
}

void *LibManager::openLib(std::string &libPath)
{
    auto it = _libsHandle.find(libPath);

    if (it == _libsHandle.end()) {
        LibraryEX("Library not found", Logger::CRITICAL);
        exit(84);
    }
    if (it->second == nullptr) {
        it->second = dlopen(libPath.c_str(), RTLD_LAZY);
        if (it->second == nullptr) {
            LibraryEX(dlerror(), Logger::CRITICAL);
            exit(84);
        }
    } else {
        LibraryEX("Library already opened", Logger::CRITICAL);
        exit(84);
    }
    return (it->second);
}

void LibManager::closeLib(std::string &libPath)
{
    auto it = _libsHandle.find(libPath);

    if (it == _libsHandle.end()) {
        LibraryEX("Library not found", Logger::CRITICAL);
        exit(84);
    }
    if (it->second != nullptr) {
        dlclose(it->second);
        it->second = nullptr;
    } else {
        LibraryEX("Library already closed", Logger::CRITICAL);
        exit(84);
    }
}

void *LibManager::getSymbol(void *libHandle, std::string &symbolName)
{
    void *symbol = dlsym(libHandle, symbolName.c_str());

    if (symbol == nullptr) {
        LibraryEX(dlerror(), Logger::CRITICAL);
        exit(84);
    }
    return (symbol);
}

void *LibManager::getSymbol(std::string &libPath, std::string &symbolName)
{
    auto it = _libsHandle.find(libPath);

    if (it == _libsHandle.end()) {
        LibraryEX("Library not found", Logger::CRITICAL);
        exit(84);
    }
    return (getSymbol(it->second, symbolName));
}
