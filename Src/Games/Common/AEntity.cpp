/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** AEntity
*/

#include "AEntity.hpp"

AEntity::AEntity()
{
    _pos = std::make_pair(0, 0);
    _size = std::make_pair(32, 32);
    _isMoving = false;
    _texturePath = "";
}

std::pair<int, int> AEntity::getPos() const
{
    return _pos;
}

void AEntity::setPos(std::pair<int, int> pos)
{
    _pos = pos;
}

std::pair<int, int> AEntity::getSize() const
{
    return _size;
}

void AEntity::setSize(std::pair<int, int> size)
{
    _size = size;
}

void AEntity::setTexturePath(std::string texturePath)
{
    _texturePath = texturePath;
}

std::string AEntity::getTexturePath() const
{
    return _texturePath;
}
