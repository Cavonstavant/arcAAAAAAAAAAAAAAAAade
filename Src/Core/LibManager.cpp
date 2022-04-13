/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManager
*/

#include "LibManager.hpp"
#include "Exception.hpp"
#include <filesystem>
#include <fstream>
#include <functional>
#include <string>

extern "C" {
#include <dlfcn.h>
}

IGame *LibManager::openGame(const std::string &libPath)
{
    unsigned long gamePathIdx = 0;
    std::string absolutePath = std::filesystem::absolute(libPath).string();

    for (; gamePathIdx < _gameLibsPaths.size(); gamePathIdx++) {
        if (_gameLibsPaths[gamePathIdx] == absolutePath)
            break;
    }
    if (gamePathIdx == _gameLibsPaths.size())
        throw FileNotFoundEX(libPath, Logger::CRITICAL);
    return _gameLibsInstances[gamePathIdx];
}

IGraph *LibManager::openGraph(const std::string &libPath)
{
    unsigned long graphPathIdx = 0;
    std::string absolute_path = std::filesystem::absolute(libPath).string();

    for (; graphPathIdx < _graphLibsPaths.size(); graphPathIdx++) {
        if (_graphLibsPaths[graphPathIdx] == absolute_path)
            break;
    }
    if (graphPathIdx == _graphLibsPaths.size())
        throw FileNotFoundEX(libPath, Logger::CRITICAL);
    return _graphLibsInstances[graphPathIdx];
}

void LibManager::addLibs()
{
    std::ifstream libConf("lib.conf");
    std::string line;
    std::stringstream ss;
    void *(*getGameInstance)();
    void *(*getGraphInstance)();

    if (libConf.is_open()) {
        while (std::getline(libConf, line)) {
            ss.clear();
            ss.str(line);
            if (line.starts_with("lib_path")) {
                ss >> line;
                ss >> line;
                break;
            }
        }
        libConf.close();
    } else
        LibraryEX("lib.conf not found at root", Logger::INFO);
    std::filesystem::path libDir(line.empty() ? "lib" : line);
    for (auto &lib: std::filesystem::directory_iterator(std::filesystem::absolute(libDir))) {
        getGameInstance = nullptr;
        getGraphInstance = nullptr;
        if (lib.path().extension() == ".so") {
            ArcadeEX("Found library: " + lib.path().filename().string(), Logger::INFO);
            try {
                void *handle = dlopen(lib.path().c_str(), RTLD_LAZY);
                if (!handle)
                    throw FileCorruptedEX(lib.path().c_str(), Logger::HIGH);
                getGraphInstance = (void *(*) ()) dlsym(handle, "getGraphInstance");
                if (getGraphInstance != nullptr) {
                    _graphLibsInstances.push_back((IGraph *) getGraphInstance());
                    _graphLibsPaths.push_back(lib.path().string());
                }
                getGameInstance = (void *(*) ()) dlsym(handle, "getGameInstance");
                if (getGameInstance != nullptr) {
                    _gameLibsInstances.push_back((IGame *) getGameInstance());
                    _gameLibsPaths.push_back(lib.path().string());
                }
                if ((getGameInstance == nullptr && getGraphInstance == nullptr) ||
                    (getGameInstance != nullptr && getGraphInstance != nullptr))
                    throw LibraryEX(dlerror(), Logger::CRITICAL);
                dlclose(handle);
            } catch (std::exception &e) {
                throw LibraryEX(e.what(), Logger::MEDIUM);
            }
        }
    }
    ArcadeEX(std::to_string(_gameLibsInstances.size() + _graphLibsInstances.size()) + std::string(" Libraries found"), Logger::INFO);
}

void LibManager::closeAllLibs()
{
    std::for_each(_gameLibsInstances.begin(), _gameLibsInstances.end(), [](auto &lib) {
        delete lib;
    });
    std::for_each(_graphLibsInstances.begin(), _graphLibsInstances.end(), [](auto &lib) {
        delete lib;
    });
}

IGame *LibManager::cycleGameLibs(std::string &currentLib, bool direction)
{
    unsigned int i;

    if (direction) {
        if (currentLib == _gameLibsInstances.front()->getLibraryName())
            return _gameLibsInstances[_gameLibsInstances.size() - 1];
        for (i = 0; i < _gameLibsInstances.size(); i++) {
            if (_gameLibsInstances[i]->getLibraryName() == currentLib)
                return (_gameLibsInstances[i - 1]);
        }
    } else {
        if (currentLib == _gameLibsInstances.back()->getLibraryName())
            return _gameLibsInstances[0];
        for (i = 0; i < _gameLibsInstances.size(); i++) {
            if (_gameLibsInstances[i]->getLibraryName() == currentLib)
                return (_gameLibsInstances[i + 1]);
        }
    }
    return nullptr;
}

IGraph *LibManager::cycleGraphLibs(std::string &currentLib, bool direction)
{
    unsigned int i;

    if (direction) {
        if (currentLib == _graphLibsInstances.front()->getLibraryName())
            return _graphLibsInstances[_graphLibsInstances.size() - 1];
        for (i = 0; i < _graphLibsInstances.size(); i++) {
            if (_graphLibsInstances[i]->getLibraryName() == currentLib)
                return (_graphLibsInstances[i - 1]);
        }
    } else {
        if (currentLib == _graphLibsInstances.back()->getLibraryName())
            return _graphLibsInstances[0];
        for (i = 0; i < _graphLibsInstances.size(); i++) {
            if (_graphLibsInstances[i]->getLibraryName() == currentLib)
                return (_graphLibsInstances[i + 1]);
        }
    }
    return nullptr;
}