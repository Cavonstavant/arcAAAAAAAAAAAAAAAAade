/*
** EPITECH PROJECT, 2022
** Enemy.cpp
** File description:
** Created by hjulien,
*/

#include "Enemy.hpp"

Enemy::Enemy() : AEntity()
{
    _speed = 0;
    _color = nullptr;
    _enrage = false;
}

Enemy::~Enemy()
{
}

void Enemy::setSpeed(int speed)
{
    _speed = speed;
}

void Enemy::setColor(IColor::COLOR_E color)
{
    _color->setColor(color);
}

void Enemy::setEnrage(bool enrage)
{
    _enrage = enrage;
}

int Enemy::getSpeed() const
{
    return _speed;
}

IColor* Enemy::getColor() const
{
    return _color;
}

bool Enemy::getEnrage() const
{
    return _enrage;
}

void Enemy::setIsMoving(bool isMoving)
{
    _isMoving = isMoving;
}
