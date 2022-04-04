/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** MainMenu
*/

#include "MainMenu.hpp"
#include "../Common/Button.hpp"
#include "../Common/TextEntity.hpp"
#include "../../Core/Exception.hpp"
#include "Event.hpp"
#include <stack>

void closeGameCallback()
{
    throw ButtonCloseGameEX("Close game button clicked", Logger::NONE);
}

MainMenu::MainMenu(std::vector<std::shared_ptr<IEntity>> &entities)
{
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
