/*
** EPITECH PROJECT, 2022
** Object.cpp.cc
** File description:
** Created by hjulien,
*/

#include "Object.hpp"

Object::Object() : AEntity()
{
}

Object::~Object()
{
}

void Object::setIsMoving(bool isMoving)
{
    (void)isMoving;
    _isMoving = false;
}

bool Object::getIsMoving() const
{
    return false;
}

void Object::setColor(Color color)
{
    _color._r = color._r;
    _color._g = color._g;
    _color._b = color._b;
    _color._a = color._a;
}

Color Object::getColor() const
{
    return _color;
}

void Object::setType(const TYPE_E type)
{
    _type = type;
}

Object::TYPE_E Object::getType() const
{
    return _type;
}
