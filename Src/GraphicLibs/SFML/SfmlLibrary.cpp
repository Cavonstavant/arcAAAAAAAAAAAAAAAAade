/*
** EPITECH PROJECT, 2022
** SfmlLibrary.cpp.cc
** File description:
** Created by hjulien,
*/

#include "SfmlLibrary.hpp"

SfmlLibrary::SfmlLibrary()
{
    const std::string font = "/Resources/Font/ARCADE_N.TTF";

    _videoMode = sf::VideoMode(1200, 800, 32);
    _font.loadFromFile(font);
    _window.create(_videoMode, "Window");
}

bool SfmlLibrary::clearWindow()
{
    _window.clear();
    return true;
}

bool SfmlLibrary::displayWindow()
{
    _window.display();
    return true;
}

bool SfmlLibrary::drawCircle(std::pair<float, float> pos, float radius, Color color)
{
    sf::CircleShape circleShape;
    sf::Color circleColor;

    circleColor.r = color.R;
    circleColor.g = color.G;
    circleColor.b = color.B;
    circleColor.a = color.A;
    circleShape.setPosition(pos.first, pos.second);
    circleShape.setRadius(radius);
    circleShape.setFillColor(circleColor);
    _window.draw(circleShape);
    return true;
}

bool SfmlLibrary::drawRect(std::pair<float, float> pos, float width, float height, Color color)
{
    sf::RectangleShape rectangleShape;
    sf::Color rectangleColor;

    rectangleColor.r = color.R;
    rectangleColor.g = color.G;
    rectangleColor.b = color.B;
    rectangleColor.a = color.A;
    rectangleShape.setPosition(pos.first, pos.second);
    rectangleShape.setSize(sf::Vector2f(width, height));
    rectangleShape.setFillColor(rectangleColor);
    _window.draw(rectangleShape);
    return true;
}

bool SfmlLibrary::drawText(std::pair<float, float> pos, const std::string &content)
{
    sf::Text text;

    text.setFont(_font);
    text.setPosition(pos.first, pos.second);
    text.setString(content);

    _window.draw(text);
    return true;
}

bool SfmlLibrary::drawEntity(IEntity &entity, std::pair<float, float> pos)
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape defaultTextureRect;

    if (texture.loadFromFile(entity.getTexturePath())) {
        sprite.setTexture(texture);
        sprite.setPosition(pos.first, pos.second);
        _window.draw(sprite);
        return true;
    } else {
        defaultTextureRect.setSize(sf::Vector2f{(float) entity.getSize().first, (float) entity.getSize().second});
        defaultTextureRect.setFillColor(sf::Color::Yellow);
        defaultTextureRect.setPosition(entity.getPos().first, entity.getPos().second);
        _window.draw(defaultTextureRect);
    }
    return false;
}
