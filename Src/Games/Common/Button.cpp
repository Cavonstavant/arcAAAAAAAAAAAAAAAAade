/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Button
*/

#include "Button.hpp"

Button::Button()
{
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
