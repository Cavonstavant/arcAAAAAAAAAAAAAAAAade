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
    Button closeGameButton(&closeGameCallback);
    closeGameButton.setPos(std::make_pair(30, 15));
    closeGameButton.setSize(std::make_pair(1, 2));
    std::shared_ptr<Button> closeGameButtonPtr = std::make_shared<Button>(closeGameButton);
    TextEntity titleText("Arcade");
    titleText.setPos(std::make_pair(0, 0));
    std::shared_ptr<TextEntity> titleTextPtr = std::make_shared<TextEntity>(titleText);

    entities.push_back(titleTextPtr);
    _buttons.push_back(closeGameButtonPtr);
    entities.push_back(closeGameButtonPtr);

    int y = 1;
    for (auto &&graphLib: _graphicalLibraries) {
        Button button(&changeGraphicalLibCallback, graphLib);
        button.setPos(std::make_pair(4, y));
        std::shared_ptr<Button> buttonPtr = std::make_shared<Button>(button);
        entities.push_back(buttonPtr);
        _buttons.push_back(buttonPtr);
        y += 2;
    }
    y = 1;
    for (auto &&gameLib: _gameLibraries) {
        Button button(&changeGameLibCallback, gameLib);
        button.setPos(std::make_pair(6, y));
        std::shared_ptr<Button> buttonPtr = std::make_shared<Button>(button);
        entities.push_back(buttonPtr);
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

void MainMenu::getAllLibraries()
{
    const std::filesystem::path path{"lib"};
    void *graphLibEntrypoint;
    void *gameLibEntrypoint;
    for (const auto &entry: std::filesystem::directory_iterator{std::filesystem::absolute(path)}) {
        try {
            void *handle = dlopen(entry.path().c_str(), RTLD_LAZY);
            if (!handle)
                continue;
            if ((graphLibEntrypoint = dlsym(handle, "getGraphInstance"))) {
                _graphicalLibraries.push_back(entry.path());
            }
            if ((gameLibEntrypoint = dlsym(handle, "getGameInstance"))) {
                _gameLibraries.push_back(entry.path());
            }
            if (gameLibEntrypoint == nullptr && graphLibEntrypoint == nullptr)
                throw FileCorruptedEX(entry.path().string() + " library corrupted", Logger::NONE);
            dlclose(handle);
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
