/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** AEntity
*/

#include "AEntity.hpp"

/// @brief Constructor
/// @param type The type of entity.
AEntity::AEntity()
{
    _pos = std::make_pair(0, 0);
    _size = std::make_pair(0, 0);
    _isMoving = false;
}

/// @brief Destructor
AEntity::~AEntity()
{
}

/// @brief Get the entity position
/// @return the std::pair<int, int> position
std::pair<int, int> AEntity::getPos() const
{
    return _pos;
}

/// @brief Set the entity position
/// @param pos the std::pair<int, int> position
void AEntity::setPos(std::pair<int, int> pos)
{
    _pos = pos;
}

/// @brief Get the entity size
/// @return the std::pair<int, int> size
std::pair<int, int> AEntity::getSize() const
{
    return _size;
}

/// @brief Set the entity size
/// @param size the std::pair<int, int> size
void AEntity::setSize(std::pair<int, int> size)
{
    _size = size;
}
