/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(std::function<void()> callbackParam, std::string actionString)
{
    callback = callbackParam;
    _actionString = actionString;
}

Button::~Button()
{
}

bool Button::isClicked(int x, int y)
{
    return (
            x >= getPos().first &&
            x <= getPos().first + getSize().first &&
            y >= getPos().second &&
            y <= getPos().second + getSize().second);
}

void Button::setIsMoving(bool isMoving)
{
    _isMoving = isMoving;
}

bool Button::getIsMoving() const
{
    return _isMoving;
}