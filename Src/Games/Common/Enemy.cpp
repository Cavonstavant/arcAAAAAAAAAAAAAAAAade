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
    _color.R = 0;
    _color.B = 0;
    _color.G = 0;
    _color.A = 255;
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
    _color.R = color.R;
    _color.G = color.G;
    _color.B = color.B;
    _color.A = color.A;
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

bool Enemy::getIsMoving() const
{
    return _isMoving;
}
