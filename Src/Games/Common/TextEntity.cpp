/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** TextEntity
*/

#include "TextEntity.hpp"

TextEntity::TextEntity(const std::string &text, const std::string &font, const int &fontSize, const Color color, const Color &outlineColor) : AEntity()
{
    _text = text;
    _fontPath = font;
    _fontSize = fontSize;
    _color = color;
    _outlineColor = outlineColor;
}

TextEntity::~TextEntity()
{
}

std::string TextEntity::getText() const
{
    return _text;
}

void TextEntity::setText(const std::string &text)
{
    _text = text;
}

std::string TextEntity::getFont() const
{
    return _fontPath;
}

void TextEntity::setFont(const std::string &font)
{
    _fontPath = font;
}

int TextEntity::getFontSize() const
{
    return _fontSize;
}

void TextEntity::setFontSize(int fontSize)
{
    _fontSize = fontSize;
}

Color TextEntity::getColor() const
{
    return _color;
}

void TextEntity::setColor(const Color color)
{
    _color = color;
}

Color TextEntity::getOutlineColor() const
{
    return _outlineColor;
}

void TextEntity::setOutlineColor(const Color &outlineColor)
{
    _outlineColor = outlineColor;
}

void TextEntity::setIsMoving(bool isMoving)
{
    _isMoving = isMoving;
}

bool TextEntity::getIsMoving() const
{
    return _isMoving;
}
