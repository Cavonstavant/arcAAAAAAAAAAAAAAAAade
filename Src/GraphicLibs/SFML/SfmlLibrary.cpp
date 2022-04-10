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
    circleShape.setPosition(GRID_INT(pos.second), GRID_INT(pos.first));
    circleShape.setRadius((float) radius);
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
    rectangleShape.setOrigin(10, 10);
    rectangleShape.setPosition(GRID_INT(pos.second), GRID_INT(pos.first));
    rectangleShape.setSize(sf::Vector2f(GRID_INT(width), GRID_INT(height)));
    rectangleShape.setFillColor(rectangleColor);
    _window.draw(rectangleShape);
    return true;
}

bool SfmlLibrary::drawText(std::pair<int, int> pos, const std::string &content, Color color)
{
    sf::Text text;
    sf::Color sfColor(color.R, color.G, color.B, color.A);

    text.setFont(_font);
    text.setPosition(GRID_INT(pos.second), GRID_INT(pos.first));
    text.setString(content);
    text.setFillColor(sfColor);

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
        sprite.setScale(1.1, 1.1);
        sprite.setOrigin(5, 5);
        sprite.setPosition(GRID_INT(pos.second), GRID_INT(pos.first));
        _window.draw(sprite);
        return true;
    } else {
        defaultTextureRect.setSize(sf::Vector2f{(float) entity.getSize().first, (float) entity.getSize().second});
        defaultTextureRect.setFillColor(sf::Color::Yellow);
        defaultTextureRect.setPosition(GRID_INT(entity.getPos().second), GRID_INT(entity.getPos().first));
        _window.draw(defaultTextureRect);
    }
    return false;
}

std::string SfmlLibrary::getLibraryName() const
{
    return "SFML";
}

Arcade::Evt SfmlLibrary::getInput()
{
    sf::Event event;
    Arcade::Evt evt;
    Arcade::Evt::KeyEvt keyEvt;

    if (!_window.pollEvent(event))
        evt.evt_type = Arcade::Evt::NONE;
    if (event.type == sf::Event::Closed)
        evt.evt_type = Arcade::Evt::WIN_CLOSE;
    if (event.type == sf::Event::KeyPressed) {
        keyEvt.state = true;
        keyEvt.modifier = Arcade::Evt::KEY_MODIFIER_NONE;
        switch (event.key.code) {
        case sf::Keyboard::Left:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'Q';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Right:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'D';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Down:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'S';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Up:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'Z';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Space:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = ' ';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::BackSpace:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '\b';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Enter:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '\n';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Escape:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 27;
            evt.key = keyEvt;
            break;
        case sf::Keyboard::A:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'a';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::B:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'b';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::C:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'c';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::D:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'd';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::E:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'e';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::F:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'f';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::G:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'g';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::H:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'h';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::I:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'i';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::J:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'j';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::K:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'k';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::L:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'l';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::M:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'm';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::N:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'N';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::O:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'o';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::P:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'p';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Q:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'q';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::R:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'r';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::S:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 's';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::T:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 't';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::U:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'u';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::V:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'v';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::W:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'w';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::X:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'x';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Y:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'y';
            evt.key = keyEvt;
            break;
        case sf::Keyboard::Z:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'z';
            evt.key = keyEvt;
            break;
        default:
            break;
        }
    }
    return evt;
}
