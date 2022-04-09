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

extern "C" {
#include <dlfcn.h>
}

LibManager::LibManager()
{
}

LibManager::LibManager(const std::vector<std::string>& libPaths)
{
    addLibs(const_cast<std::vector<std::string>&>(libPaths));
    for (auto &libPath: libPaths) {
        _libsHandle.emplace(libPath, nullptr);
    }
}

IGame *LibManager::openGame(const std::string& libPath)
{
    if (_libsHandle.find(std::filesystem::absolute(std::filesystem::path(libPath))) == _libsHandle.end())
        throw ArcadeEX(libPath + " not found", Logger::HIGH);
    void *libHandle = dlopen(libPath.c_str(), RTLD_NOW);
    if (!libHandle)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    if (_libsHandle[libPath])
        throw ArcadeEX(libPath + "is already opened", Logger::NONE);
    _libsHandle[libPath] = libHandle;
    IGame *gameInstance = reinterpret_cast<IGame *>(dlsym(libHandle, "getGameInstance"));
    if (gameInstance == nullptr)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    return (gameInstance);
}

IGraph *LibManager::openGraph(const std::string& libPath)
{
    if (_libsHandle.find(std::filesystem::absolute(std::filesystem::path(libPath))) == _libsHandle.end())
        throw ArcadeEX(libPath + " not found", Logger::HIGH);
    void *libHandle = dlopen(libPath.c_str(), RTLD_NOW);
    if (libHandle == nullptr)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    if (_libsHandle[libPath])
        throw ArcadeEX(libPath + "is already opened", Logger::HIGH);
    _libsHandle[libPath] = libHandle;
    IGraph *graphInstance = reinterpret_cast<IGraph*>(dlsym(libHandle, "getGraphInstance"));
    if (graphInstance == nullptr)
        throw LibraryEX(dlerror(), Logger::CRITICAL);
    return (graphInstance);
}

void LibManager::closeLib(const std::string& libPath)
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
            _libsHandle.emplace((lib.path().filename().string(), lib.path().string()), nullptr);
        }
    }
    ArcadeEX(std::to_string(_libsHandle.size()) + std::string(" Libraries found"), Logger::INFO);
    std::for_each(libPaths.begin(), libPaths.end(), [this](std::string &libPath) {
        _libsHandle.emplace(std::filesystem::absolute(std::filesystem::path(libPath)), nullptr);
    });
}
