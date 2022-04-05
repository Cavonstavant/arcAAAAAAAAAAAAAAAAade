/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** MainMenu
*/

#include "MainMenu.hpp"
#include "../../Core/Exception.hpp"
#include "../../Games/Common/Button.hpp"
#include "../../Games/Common/TextEntity.hpp"
#include "Event.hpp"
#include <dlfcn.h>
#include <filesystem>
#include <stack>

void closeGameCallback()
{
    throw ButtonCloseGameEX("Close game button clicked", Logger::NONE);
}

MainMenu::MainMenu(std::vector<std::shared_ptr<IEntity>> &entities)
{
    getAllLibraries();
    _gameState = GameState::LOADED;
    Button startGameButton;
    std::shared_ptr<Button> startGameButtonPtr = std::make_shared<Button>(startGameButton);

    startGameButton.callback = &closeGameCallback;
    entities.push_back(std::make_shared<TextEntity>("Arcade"));
    _buttons.push_back(startGameButtonPtr);
    entities.push_back(startGameButtonPtr);
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
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
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
