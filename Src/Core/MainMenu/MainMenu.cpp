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

static void createVerticalText(std::vector<std::shared_ptr<IEntity>> &entities, const std::string &text, int x, int y)
{
    for (auto &c : text) {
        std::string chString(1, c);
        TextEntity textChar(chString);
        textChar.setPos(std::make_pair(x, y));
        std::shared_ptr<TextEntity> textCharPtr = std::make_shared<TextEntity>(textChar);
        entities.push_back(textCharPtr);
        x += 1;
    }
}

static void createBox(std::vector<std::shared_ptr<IEntity>> &entities, int x, int y, int width, int height)
{
    Object box(Object::ENTITY_TYPE::WALL);
    box.setPos(std::make_pair(x, y));
    box.setSize(std::make_pair(width, height));
    box.setColor({0, 255, 255, 255, Color::TermColors::CYAN});
    std::shared_ptr<Object> boxPtr = std::make_shared<Object>(box);
    entities.push_back(boxPtr);
}

static void createText(std::vector<std::shared_ptr<IEntity>> &entities, std::string text, int x, int y, Color color)
{
    TextEntity textEntity(text);
    textEntity.setPos(std::make_pair(x, y));
    textEntity.setColor(color);
    std::shared_ptr<TextEntity> textEntityPtr = std::make_shared<TextEntity>(textEntity);
    entities.push_back(textEntityPtr);
}

void MainMenu::init(std::vector<std::shared_ptr<IEntity>> &entities)
{
    _graphicalLibraries.clear();
    _gameLibraries.clear();
    getAllLibraries();

    _gameState = GameState::LOADED;

    TextEntity titleText("Arcade");
    titleText.setPos(std::make_pair(0, 0));
    std::shared_ptr<TextEntity> titleTextPtr = std::make_shared<TextEntity>(titleText);

    Button closeGameButton(&closeGameCallback);
    closeGameButton.setPos(std::make_pair(11, 2));
    closeGameButton.setSize(std::make_pair(1, 1));
    std::shared_ptr<Button> closeGameButtonPtr = std::make_shared<Button>(closeGameButton);

    createBox(entities, 1, 1, GRID_INT(1) / 8, GRID_HEIGHT - 1);
    createBox(entities, 1, GRID_INT(1) / 8 + 2, GRID_INT(1) / 3 + 3, GRID_HEIGHT - 1);
    createBox(entities, 1, GRID_INT(1) / 8 + 2 + GRID_INT(1) / 3 + 3 + 1, GRID_INT(1) / 3 + 3, GRID_HEIGHT - 1);

    _buttons.push_back(closeGameButtonPtr);
    entities.push_back(closeGameButtonPtr);
    entities.push_back(titleTextPtr);

    createText(entities, "1", 11, 2, {0, 0, 0, 255, Color::TermColors::BLACK, Color::TermColors::WHITE});

    createVerticalText(entities, "Close", 12, 2);

    int x = 2;
    int y = 7;
    char c = 'a';
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
        text.setPos(std::make_pair(x, y + 2));

        std::shared_ptr<Button> buttonPtr = std::make_shared<Button>(button);
        std::shared_ptr<TextEntity> textPtr = std::make_shared<TextEntity>(text);

        entities.push_back(buttonPtr);
        entities.push_back(textPtr);

        _buttons.push_back(buttonPtr);

        std::string buttonKeyString(&c, 1);
        createText(entities, buttonKeyString, x, y, {0, 0, 0, 255, Color::TermColors::BLACK, Color::TermColors::WHITE});
        c++;

        x += 2;
    }
    x = 2;
    y = 21;
    for (auto &&gameLib: _gameLibraries) {
        Button button(&changeGameLibCallback, gameLib);
        std::string libName = gameLib;
        try {
            libName = gameLib.substr(gameLib.find_last_of("/") + 1);
            libName = libName.substr(libName.find_first_not_of("arcade_"));
            libName = libName.substr(0, libName.find_last_of("."));
        } catch (...) {}
        TextEntity text(libName);

        button.setPos(std::make_pair(x, y));
        text.setPos(std::make_pair(x, y + 2));

        std::shared_ptr<Button> buttonPtr = std::make_shared<Button>(button);
        std::shared_ptr<TextEntity> textPtr = std::make_shared<TextEntity>(text);

        entities.push_back(buttonPtr);
        entities.push_back(textPtr);

        _buttons.push_back(buttonPtr);


        std::string buttonKeyString(&c, 1);
        createText(entities, buttonKeyString, x, y, {0, 0, 0, 255, Color::TermColors::BLACK, Color::TermColors::WHITE});
        c++;

        x += 2;
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
    char c = 'a';
    for (auto &graph: _graphicalLibraries) {
        if (c >= 'z')
            break;
        if (event.key.key == c)
            throw SwitchLibEX("Graph;" + graph, Logger::NONE);
        c++;
    }
    for (auto &game: _gameLibraries) {
        if (c >= 'z')
            break;
        if (event.key.key == c)
            throw SwitchLibEX("Game;" + game, Logger::NONE);
        c++;
    }
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
    const std::filesystem::path path{"./lib/"};
    std::string libName;
    void *libNameFct;

    for (const auto &entry: std::filesystem::directory_iterator{path}) {
        if (entry.path().extension() != ".so")
            continue;
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

bool MainMenu::getIsGameOver()
{
    return false;
}

int MainMenu::getScore() const
{
    return -1;
}
