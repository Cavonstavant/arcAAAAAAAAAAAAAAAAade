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
    _color._r = 0;
    _color._b = 0;
    _color._g = 0;
    _color._a = 255;
    _enrage = false;
}

Enemy::~Enemy()
{
}

void Enemy::setSpeed(int speed)
{
    _speed = speed;
}

void Enemy::setColor(Color color)
{
    _color._r = color._r;
    _color._g = color._g;
    _color._b = color._b;
    _color._a = color._a;
}

void Enemy::setEnrage(bool enrage)
{
    _enrage = enrage;
}

int Enemy::getSpeed() const
{
    return _speed;
}

Color Enemy::getColor() const
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
