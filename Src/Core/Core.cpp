/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#include "Core.hpp"

void Core::addEntity(std::shared_ptr<IEntity> entity)
{
    _entities.push_back(entity);
}

void Core::removeEntity(std::shared_ptr<IEntity> entity)
{
    _entities.erase(std::remove(_entities.begin(), _entities.end(), entity), _entities.end());
}

std::vector<std::shared_ptr<IEntity>>& Core::getEntities()
{
    return _entities;
}