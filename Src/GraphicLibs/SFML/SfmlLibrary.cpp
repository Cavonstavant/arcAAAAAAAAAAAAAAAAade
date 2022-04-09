/*
** EPITECH PROJECT, 2022
** SfmlLibrary.cpp.cc
** File description:
** Created by hjulien,
*/

#include "SfmlLibrary.hpp"
#include <filesystem>

void SfmlLibrary::init()
{
    const std::string font = "Src/GraphicLibs/Resources/Font/ARCADE_N.TTF";

    _videoMode = sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, 32);
    _font.loadFromFile(std::filesystem::absolute(std::filesystem::path(font)).string());
    _window.create(_videoMode, "Window");
    _window.setFramerateLimit(32);
}

void SfmlLibrary::close()
{
    _window.close();
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

bool SfmlLibrary::drawCircle(std::pair<int, int> pos, int radius, Color color)
{
    sf::CircleShape circleShape;
    sf::Color circleColor;

    circleColor.r = color.R;
    circleColor.g = color.G;
    circleColor.b = color.B;
    circleColor.a = color.A;
    circleShape.setPosition(GRID_INT(pos.first), GRID_INT(pos.second));
    circleShape.setRadius((float) GRID_INT(radius));
    circleShape.setFillColor(circleColor);
    _window.draw(circleShape);
    return true;
}

bool SfmlLibrary::drawRect(std::pair<int, int> pos, int width, int height, Color color)
{
    sf::RectangleShape rectangleShape;
    sf::Color rectangleColor;

    rectangleColor.r = color.R;
    rectangleColor.g = color.G;
    rectangleColor.b = color.B;
    rectangleColor.a = color.A;
    rectangleShape.setPosition(GRID_INT(pos.first), GRID_INT(pos.second));
    rectangleShape.setSize(sf::Vector2f(GRID_INT(width), GRID_INT(height)));
    rectangleShape.setFillColor(rectangleColor);
    _window.draw(rectangleShape);
    return true;
}

bool SfmlLibrary::drawText(std::pair<int, int> pos, const std::string &content)
{
    sf::Text text;

    text.setFont(_font);
    text.setPosition(GRID_INT(pos.first), GRID_INT(pos.second));
    text.setString(content);

    _window.draw(text);
    return true;
}

bool SfmlLibrary::drawEntity(IEntity &entity, std::pair<int, int> pos)
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape defaultTextureRect;

    if (texture.loadFromFile(entity.getTexturePath())) {
        sprite.setTexture(texture);
        sprite.setPosition(GRID_INT(pos.first), GRID_INT(pos.second));
        _window.draw(sprite);
        return true;
    } else {
        defaultTextureRect.setSize(sf::Vector2f{(float) (int) entity.getSize().first, (float) (int) entity.getSize().second});
        defaultTextureRect.setFillColor(sf::Color::Yellow);
        defaultTextureRect.setPosition(GRID_INT(entity.getPos().first), GRID_INT(entity.getPos().second));
        _window.draw(defaultTextureRect);
    }
    return false;
}

std::string SfmlLibrary::getLibraryName() const
{
    return "SFML";
}

Arcade::Evt SfmlLibrary::getInput() const
{
    sf::Event event{};
    Arcade::Evt evt{};
    Arcade::Evt::KeyEvt keyEvt{};

    if (event.type == sf::Event::Closed)
        evt.evt_type = Arcade::Evt::WIN_CLOSE;
    if (event.type == sf::Event::KeyPressed) {
        keyEvt.state = true;
        keyEvt.modifier = Arcade::Evt::KEY_MODIFIER_NONE;
        switch (event.key.code) {
            case sf::Keyboard::Left:
                keyEvt.key = 'Q';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Right:
                keyEvt.key = 'D';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Down:
                keyEvt.key = 'S';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Up:
                keyEvt.key = 'Z';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Space:
                keyEvt.key = ' ';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::BackSpace:
                keyEvt.key = '\b';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Enter:
                keyEvt.key = '\n';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Escape:
                keyEvt.key = 27;
                evt.key = keyEvt;
                break;
            case sf::Keyboard::A:
                keyEvt.key = 'a';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::B:
                keyEvt.key = 'b';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::C:
                keyEvt.key = 'c';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::D:
                keyEvt.key = 'd';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::E:
                keyEvt.key = 'e';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::F:
                keyEvt.key = 'f';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::G:
                keyEvt.key = 'g';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::H:
                keyEvt.key = 'h';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::I:
                keyEvt.key = 'i';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::J:
                keyEvt.key = 'j';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::K:
                keyEvt.key = 'k';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::L:
                keyEvt.key = 'l';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::M:
                keyEvt.key = 'm';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::N:
                keyEvt.key = 'N';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::O:
                keyEvt.key = 'o';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::P:
                keyEvt.key = 'p';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Q:
                keyEvt.key = 'q';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::R:
                keyEvt.key = 'r';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::S:
                keyEvt.key = 's';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::T:
                keyEvt.key = 't';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::U:
                keyEvt.key = 'u';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::V:
                keyEvt.key = 'v';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::W:
                keyEvt.key = 'w';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::X:
                keyEvt.key = 'x';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Y:
                keyEvt.key = 'y';
                evt.key = keyEvt;
                break;
            case sf::Keyboard::Z:
                keyEvt.key = 'z';
                evt.key = keyEvt;
                break;
            default:
                break;
        }
    }
    return evt;
}