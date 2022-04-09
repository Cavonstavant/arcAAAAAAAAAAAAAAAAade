/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** MainMenu
*/

#include "MainMenu.hpp"
#include "Button.hpp"
#include "TextEntity.hpp"
#include "../Exception.hpp"
#include "Event.hpp"
extern "C" {
    #include <dlfcn.h>
}
#include <filesystem>
#include <stack>

static void closeGameCallback()
{
    throw ButtonCloseGameEX("Close game button clicked", Logger::NONE);
}

static void changeGraphicalLibCallback()
{
    throw NotImplementedEX("Change graphical lib button clicked", Logger::NONE);
}

static void changeGameLibCallback()
{
    throw NotImplementedEX("Change graphical lib button clicked", Logger::NONE);
}

MainMenu::MainMenu()
{
    _gameState = GameState::LOADED;
}

MainMenu::~MainMenu()
{
}

void MainMenu::init(std::vector<std::shared_ptr<IEntity>> &entities)
{
    getAllLibraries();

    _gameState = GameState::LOADED;

    TextEntity titleText("Arcade");
    titleText.setPos(std::make_pair(0, 0));
    std::shared_ptr<TextEntity> titleTextPtr = std::make_shared<TextEntity>(titleText);

    Button closeGameButton(&closeGameCallback);
    closeGameButton.setPos(std::make_pair(14, 28));
    closeGameButton.setSize(std::make_pair(4, 2));
    std::shared_ptr<Button> closeGameButtonPtr = std::make_shared<Button>(closeGameButton);

    TextEntity closeText("Close");
    closeText.setPos(std::make_pair(15, 29));
    std::shared_ptr<TextEntity> closeTextPtr = std::make_shared<TextEntity>(closeText);

    entities.push_back(titleTextPtr);
    entities.push_back(closeTextPtr);
    _buttons.push_back(closeGameButtonPtr);
    entities.push_back(closeGameButtonPtr);

    int y = 1;
    int x = 4;
    for (auto &&graphLib: _graphicalLibraries) {
        Button button(&changeGraphicalLibCallback, graphLib);
        std::string libName = graphLib;
        try {
            libName = graphLib.substr(graphLib.find_last_of("/") + 1);
            libName = libName.substr(libName.find_first_not_of("arcade_"));
            libName = libName.substr(0, libName.find_last_of("."));
        } catch (...) {}
        TextEntity text(libName);

        button.setPos(std::make_pair(x, y));
        text.setPos(std::make_pair(x + 2, y));

        std::shared_ptr<Button> buttonPtr = std::make_shared<Button>(button);
        std::shared_ptr<TextEntity> textPtr = std::make_shared<TextEntity>(text);

        entities.push_back(buttonPtr);
        entities.push_back(textPtr);

        _buttons.push_back(buttonPtr);

        y += 2;
    }
    y = 1;
    x = 10;
    for (auto &&gameLib: _gameLibraries) {
        Button button(&changeGameLibCallback, gameLib);
        std::string libName = gameLib;
        try {
            libName = gameLib.substr(gameLib.find_last_of("/") + 1);
            libName = libName.substr(libName.find_first_not_of("arcade_"));
            libName = libName.substr(0, libName.find_last_of("."));
        } catch (...) {}
        TextEntity text(gameLib);

        button.setPos(std::make_pair(x, y));
        text.setPos(std::make_pair(x + 2, y));

        std::shared_ptr<Button> buttonPtr = std::make_shared<Button>(button);
        std::shared_ptr<TextEntity> textPtr = std::make_shared<TextEntity>(text);

        entities.push_back(buttonPtr);
        entities.push_back(textPtr);

        _buttons.push_back(buttonPtr);

        y += 2;
    }
}

void MainMenu::close(std::vector<std::shared_ptr<IEntity>> &entities)
{
    while (!entities.empty())
        entities.pop_back();
}

void MainMenu::manageClickEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities)
{
    for (auto &button: _buttons) {
        if (button->isClicked(event.mouse.x, event.mouse.y)) {
            button->callback();
        }
    }
}

void MainMenu::manageKeyEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities)
{
    throw NotImplementedEX("Key event not implemented", Logger::HIGH);
}

void MainMenu::manageEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities)
{
    if (event.evt_type == Arcade::Evt::EvtType::MOUSE_CLICK)
        manageClickEvent(event, entities);
    else if (event.evt_type == Arcade::Evt::EvtType::KEY)
        manageKeyEvent(event, entities);
}

void MainMenu::update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events)
{
    while (!events.empty()) {
        manageEvent(events.top(), entities);
        events.pop();
    }
}

void MainMenu::start()
{
    _gameState = GameState::RUNNING;
}

// void MainMenu::getAllLibraries()
// {
//     const std::filesystem::path path{"./lib"};
//     std::string libName;
//     void *libNameFct;

//     for (const auto &entry: std::filesystem::directory_iterator{path}) {
//         // std::string libPath = std::filesystem::absolute(entry.path()).string();
//         // std::cout << libPath << std::endl;
//         try {
//             try {
//                 IGame *game = _libManager.openGame(entry.path());
//                 _gameLibraries.push_back(game->getLibraryName());
//             } catch (...) {
//                 try {
//                     IGraph *graph = _libManager.openGraph(entry.path());
//                     _graphicalLibraries.push_back(graph->getLibraryName());
//                 } catch (...) {
//                     LibraryEX(entry.path().string() + " is invalid", Logger::LOW);
//                 }
//             }
//         } catch (std::exception &e) {
//             throw LibraryEX(e.what(), Logger::MEDIUM);
//         }
//     }
//     ArcadeEX(std::string("successfully load all libraries in: ") + std::filesystem::absolute(path).string(), Logger::INFO);
// }

void MainMenu::getAllLibraries()
{
    const std::filesystem::path path{"./lib/"};
    std::string libName;
    void *libNameFct;

    for (const auto &entry: std::filesystem::directory_iterator{path}) {
        try {
            void *handle = dlopen(entry.path().c_str(), RTLD_LAZY);
            if (!handle)
                continue;
            if (dlsym(handle, "getGraphInstance")) {
                libNameFct = dlsym(handle, "getLibraryName");
                if (!libNameFct)
                    _graphicalLibraries.push_back(entry.path());
                else
                    _graphicalLibraries.push_back(reinterpret_cast<std::string(*)()>(libNameFct)());
            } else if (dlsym(handle, "getGameInstance")) {
                libNameFct = dlsym(handle, "getLibraryName");
                if (!libNameFct)
                    _gameLibraries.push_back(entry.path());
                else
                    _gameLibraries.push_back(reinterpret_cast<std::string(*)()>(libNameFct)());
            }
//            dlclose(handle);
        } catch (std::exception &e) {
            throw LibraryEX(e.what(), Logger::MEDIUM);
        }
    }
    ArcadeEX(std::string("successfully load all libraries in: ") + std::filesystem::absolute(path).string(), Logger::INFO);
}

std::string MainMenu::getLibraryName() const
{
    return "Main Menu";
}
