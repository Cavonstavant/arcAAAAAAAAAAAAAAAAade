/*
** EPITECH PROJECT, 2022
** Object.cpp.cc
** File description:
** Created by hjulien,
*/

#include "Object.hpp"

Object::Object(AEntity::ENTITY_TYPE type)
{
    _type = type;
    if (_type == POINT || _type == BONUS) {
        _color.R = 255;
        _color.G = 255;
        _color.B = 0;
        _color.A = 255;
        _termTexture = std::make_pair(type == BONUS ? 'o' : '.', std::make_pair(Color::TermColors::YELLOW, Color::TermColors::BLACK));
    } else if (_type == WALL) {
        _color.R = 0;
        _color.G = 0;
        _color.B = 255;
        _color.A = 255;
        _termTexture = std::make_pair('X', std::make_pair(Color::TermColors::BLUE, Color::TermColors::WHITE));
    }
}

Object::~Object()
{
}

void Object::setIsMoving(bool isMoving)
{
    (void) isMoving;
    _isMoving = false;
}

bool Object::getIsMoving() const
{
    return false;
}

void Object::setColor(Color color)
{
    _color.R = color.R;
    _color.G = color.G;
    _color.B = color.B;
    _color.A = color.A;
}

Color Object::getColor() const
{
    return _color;
}

void Object::setType(const ENTITY_TYPE type)
{
    _type = type;
}

Object::ENTITY_TYPE Object::getType() const
{
    return _type;
}
