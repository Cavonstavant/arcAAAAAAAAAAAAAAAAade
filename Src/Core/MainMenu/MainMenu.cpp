/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** MainMenu
*/

#include "MainMenu.hpp"
#include "../Exception.hpp"
#include "../../Games/Common/Button.hpp"
#include "../../Games/Common/TextEntity.hpp"
#include "Event.hpp"
#include <dlfcn.h>
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

MainMenu::MainMenu(std::vector<std::shared_ptr<IEntity>> &entities)
{
    getAllLibraries();

    _gameState = GameState::LOADED;
    Button startGameButton(&closeGameCallback);
    std::shared_ptr<Button> startGameButtonPtr = std::make_shared<Button>(startGameButton);

    entities.push_back(std::make_shared<TextEntity>("Arcade"));
    _buttons.push_back(startGameButtonPtr);
    entities.push_back(startGameButtonPtr);

    int y = 100;
    for (auto &&graphLib: _graphicalLibraries) {
        Button button(&changeGraphicalLibCallback, graphLib);
        button.setPos(std::make_pair(200, y));
        std::shared_ptr<Button> buttonPtr = std::make_shared<Button>(button);
        entities.push_back(buttonPtr);
        _buttons.push_back(buttonPtr);
        y += (button.getSize().second * 4 / 3);
    }
    y = 100;
    for (auto &&gameLib: _gameLibraries) {
        Button button(&changeGameLibCallback, gameLib);
        button.setPos(std::make_pair(500, y));
        std::shared_ptr<Button> buttonPtr = std::make_shared<Button>(button);
        entities.push_back(buttonPtr);
        _buttons.push_back(buttonPtr);
        y += (button.getSize().second * 4 / 3);
    }
}

MainMenu::~MainMenu()
{
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
    while (events.size() > 0) {
        manageEvent(events.top(), entities);
        events.pop();
    }
}

void MainMenu::start()
{
    _gameState = GameState::RUNNING;
}

void MainMenu::getAllLibraries()
{
    std::string path = "../../../lib";
    for (const auto &entry: std::filesystem::directory_iterator(path)) {
        try {
            void *handle = dlopen(entry.path().c_str(), RTLD_LAZY);
            if (!handle)
                continue;
            if (dlsym(handle, "getGraphInstance")) {
                _graphicalLibraries.push_back(entry.path());
            } else if (dlsym(handle, "getGameInstance")) {
                _gameLibraries.push_back(entry.path());
            }
            dlclose(handle);
        } catch (std::exception &e) {
            throw LibraryEX(e.what(), Logger::MEDIUM);
        }
    }
}
