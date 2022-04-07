/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManager
*/

#include "LibManager.hpp"
#include "Exception.hpp"
#include <fstream>
#include <sstream>
#include <string>

extern "C" {
#include <dlfcn.h>
}

LibManager::LibManager()
{
    loadGameLibs();
}

LibManager::LibManager(std::vector<std::string> libPaths)
{
    loadGameLibs();
    for (auto &libPath: libPaths) {
        _libsHandle.emplace(libPath, nullptr);
    }
}

void *LibManager::openLib(std::string libPath)
{
    auto it = _libsHandle.find(libPath);

    if (it == _libsHandle.end())
        throw LibraryEX("Library not found", Logger::CRITICAL);
    if (it->second == nullptr) {
        it->second = dlopen(libPath.c_str(), RTLD_LAZY);
        if (it->second == nullptr)
            throw LibraryEX(dlerror(), Logger::CRITICAL);
    } else
        throw LibraryEX("Library already opened", Logger::CRITICAL);
    return (it->second);
}

IGame *LibManager::openGame(std::string libPath)
{
    void *libHandle = openLib(libPath);
    IGame *(*createGame)();

    createGame = (IGame * (*) (void) ) dlsym(libHandle, "createGame");
    if (createGame == nullptr)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    return (createGame());
}

IGraph *LibManager::openGraph(std::string libPath)
{
    void *libHandle = openLib(libPath);
    IGraph *(*createGraph)();

    createGraph = (IGraph * (*) (void) ) dlsym(libHandle, "createGraph");
    if (createGraph == nullptr)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    return (createGraph());
}

void LibManager::closeLib(std::string libPath)
{
    auto it = _libsHandle.find(libPath);

    if (it == _libsHandle.end())
        throw LibraryEX("Library not found", Logger::CRITICAL);
    if (it->second != nullptr) {
        dlclose(it->second);
        it->second = nullptr;
    } else
        throw LibraryEX("Library already closed", Logger::CRITICAL);
}

void LibManager::loadGameLibs()
{
    std::ifstream libConf("lib.conf");
    std::string libPath = "./lib";

    if (libConf.is_open()) {
        std::string line;
        std::stringstream ss;

        while (std::getline(libConf, line)) {
            ss.clear();
            ss.str(line);
            if (line == "[libPath]"){
                ss >> libPath;
                _libsHandle.emplace(libPath, nullptr);
            }
        }
        libConf.close();
    } else
        LibraryEX("lib.conf not found at root", Logger::INFO);
}

void LibManager::addLib(std::vector<std::string> libPaths)
{
    for (auto &libPath: libPaths) {
        _libsHandle.emplace(libPath, nullptr);
    }
}