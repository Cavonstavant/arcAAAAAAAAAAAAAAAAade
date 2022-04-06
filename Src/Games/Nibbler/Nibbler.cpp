/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "../../Games/Common/Button.hpp"
#include "../../Games/Common/TextEntity.hpp"
#include "Event.hpp"
#include <stack>

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

void Nibbler::init(std::vector<std::shared_ptr<IEntity>> &entities)
{
    _gameState = GameState::LOADED;
    Player head;
    head.setPos(std::make_pair(GRID_WIDTH / 2, GRID_HEIGHT / 2));
    // head.set
    Player tail1;
    tail1.setPos(std::make_pair(GRID_WIDTH / 2 - 1, GRID_HEIGHT / 2));
}

void Nibbler::manageKeyEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities)
{
    if (event.key.key == 'Q') {
    }
}

void Nibbler::manageEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities)
{
    if (event.evt_type == Arcade::Evt::EvtType::KEY)
        manageKeyEvent(event, entities);
}

void Nibbler::update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events)
{
    while (events.size() > 0) {
        manageEvent(events.top(), entities);
        events.pop();
    }
}

void Nibbler::start()
{
    _gameState = GameState::RUNNING;
}

std::string Nibbler::getLibraryName() const
{
    return "Nibbler";
}
