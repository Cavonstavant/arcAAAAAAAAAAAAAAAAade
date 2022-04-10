/*
** EPITECH PROJECT, 2022
** Player.cpp.cc
** File description:
** Created by hjulien,
*/

#include "Player.hpp"

Player::Player() : AEntity()
{
}

Player::~Player()
{
}

void Player::setIsMoving(bool isMoving)
{
    _isMoving = isMoving;
}

bool Player::getIsMoving() const
{
    return _isMoving;
}

void Player::setBoosted(const bool boosted)
{
    _boosted = boosted;
}

bool Player::getBoosted() const
{
    return _boosted;
}
