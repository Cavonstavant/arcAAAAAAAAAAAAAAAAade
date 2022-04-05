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
    _termTexture = std::make_pair('x', std::make_pair(Color::TermColors::WHITE, Color::TermColors::BLACK));
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

void AEntity::setTermTexture(char c, Color::TermColors fg, Color::TermColors bg)
{
    _termTexture = std::make_pair(c, std::make_pair(fg, bg));
}

std::pair<char, std::pair<Color::TermColors, Color::TermColors>> AEntity::getTermTexture() const
{
    return _termTexture;
}
