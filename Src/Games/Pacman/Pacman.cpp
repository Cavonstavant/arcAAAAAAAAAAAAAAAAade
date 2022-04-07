/*
** EPITECH PROJECT, 2022
** Pacman.cpp.cc
** File description:
** Created by hjulien,
*/

#include "Pacman.hpp"

Pacman::Pacman() {

}

std::string Pacman::getName() const
{
    return "Pacman";
}

void Pacman::update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events)
{

}

IGame::GameState Pacman::getState() const
{
    return IGame::GameState::PAUSED;
}

void Pacman::start()
{

}

bool Pacman::moveUp(Arcade::Evt input)
{
    return false;
}

bool Pacman::moveDown(Arcade::Evt input)
{
    return false;
}

bool Pacman::moveRight(Arcade::Evt input)
{
    return false;
}

bool Pacman::moveLeft(Arcade::Evt input)
{
    return false;
}
