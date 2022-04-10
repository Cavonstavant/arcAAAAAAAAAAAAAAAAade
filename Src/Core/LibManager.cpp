/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManager
*/

#include "LibManager.hpp"
#include "Exception.hpp"
#include <fstream>
#include <string>
#include <filesystem>
#include <functional>

extern "C" {
#include <dlfcn.h>
}

IGame *LibManager::openGame(const std::string &libPath) {
    if (_libsHandle.find(std::filesystem::absolute(std::filesystem::path(libPath))) == _libsHandle.end())
        throw ArcadeEX(libPath + " not found", Logger::HIGH);
    void *libHandle = dlopen(libPath.c_str(), RTLD_NOW);
    if (!libHandle)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    if (_libsHandle[libPath])
        throw ArcadeEX(libPath + "is already opened", Logger::NONE);
    _libsHandle[libPath] = libHandle;
    void *(*getInstance)();
    getInstance = (void *(*)()) dlsym(libHandle, "getGameInstance");
    if (getInstance == nullptr)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    return ((IGame *)getInstance());
}

IGraph *LibManager::openGraph(const std::string &libPath) {
    if (_libsHandle.find(std::filesystem::absolute(std::filesystem::path(libPath))) == _libsHandle.end())
        throw ArcadeEX(libPath + " not found", Logger::HIGH);
    void *libHandle = dlopen(libPath.c_str(), RTLD_NOW);
    if (libHandle == nullptr)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    if (_libsHandle[libPath])
        throw ArcadeEX(libPath + "is already opened", Logger::HIGH);
    _libsHandle[libPath] = libHandle;
    void *(*getInstance)();
    getInstance = (void *(*)()) dlsym(libHandle, "getGraphInstance");
    if (getInstance == nullptr)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    return ((IGraph*)getInstance());
}

void LibManager::closeLib(const std::string& libPath)
{
    auto it = _libsHandle.find(std::filesystem::absolute(std::filesystem::path(libPath)));

    if (it == _libsHandle.end())
        throw LibraryEX("Library not found", Logger::CRITICAL);
    if (it->second != nullptr) {
        dlclose(it->second);
        it->second = nullptr;
    } else
        throw LibraryEX("Library already closed", Logger::CRITICAL);
}

void LibManager::addLibs(std::vector<std::string> &libPaths) {
    std::ifstream libConf("lib.conf");
    std::string line;
    std::stringstream ss;

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
        if (lib.path().extension() == ".so") {
            ArcadeEX("Found library: " + lib.path().filename().string(), Logger::INFO);
            _libsHandle.emplace(lib.path().string(), nullptr);
                try {
                    void *handle = dlopen(lib.path().c_str(), RTLD_LAZY);
                    if (!handle)
                        continue;
                    if (dlsym(handle, "getGraphInstance")) {
                        _graphLibsName.push_back(lib.path());
                    } else if (dlsym(handle, "getGameInstance")) {
                        _gameLibsName.push_back(lib.path());
                    }
//                    dlclose(handle);
                } catch (std::exception &e) {
                    throw LibraryEX(e.what(), Logger::MEDIUM);
                }
            }
        }
    ArcadeEX(std::to_string(_libsHandle.size()) + std::string(" Libraries found"), Logger::INFO);
    std::for_each(libPaths.begin(), libPaths.end(), [this](std::string &libPath) {
        _libsHandle.emplace(std::filesystem::absolute(std::filesystem::path(libPath)), nullptr);
    });
}

void LibManager::closeAllLibs()
{
    for (auto &lib: _libsHandle) {
        if (lib.second != nullptr) {
            dlclose(lib.second);
            lib.second = nullptr;
        }
    }
}

IGame *LibManager::cycleGameLibs(std::string &currentLib, bool direction)
{
    if (_gameLibsName.empty())
        throw ArcadeEX("No game library found", Logger::CRITICAL);
    if (currentLib.empty())
        currentLib = _gameLibsName[0];
    auto libNameIt = std::find(_gameLibsName.begin(), _gameLibsName.end(), currentLib);

    if (direction) {
        if (libNameIt == _gameLibsName.end() || libNameIt == _gameLibsName.begin())
            return nullptr;
        if (libNameIt == _gameLibsName.end() - 1)
            return ((IGame *)openGame(_gameLibsName[0]));
        return openGame(*(libNameIt - 1));
    } else {
        if (libNameIt == _gameLibsName.end() || libNameIt == _gameLibsName.begin() + 1)
            return nullptr;
        if (libNameIt == _gameLibsName.begin())
            return ((IGame *)openGame(_gameLibsName.back()));
        return openGame(*(libNameIt + 1));
    }
}

IGraph *LibManager::cycleGraphLibs(std::string &currentLib, bool direction)
{
    if (_graphLibsName.empty())
        throw ArcadeEX("No graph library found", Logger::CRITICAL);
    if (currentLib.empty())
        currentLib = _graphLibsName[0];
    auto libNameIt = std::find(_graphLibsName.begin(), _graphLibsName.end(), currentLib);

    if (direction) {
        if (libNameIt == _graphLibsName.end() || libNameIt == _graphLibsName.begin())
            return nullptr;
        if (libNameIt == _graphLibsName.end() - 1)
            return ((IGraph *)openGraph(_graphLibsName[0]));
        return openGraph(*(libNameIt - 1));
    } else {
        if (libNameIt == _graphLibsName.end() || libNameIt == _graphLibsName.begin() + 1)
            return nullptr;
        if (libNameIt == _graphLibsName.begin())
            return ((IGraph *)openGraph(_graphLibsName.back()));
        return openGraph(*(libNameIt + 1));
    }
}