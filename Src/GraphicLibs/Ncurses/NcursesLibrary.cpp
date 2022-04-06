/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** NcursesLibrary
*/

#include "NcursesLibrary.hpp"

NcursesLibrary::NcursesLibrary()
{
    initscr();
}

NcursesLibrary::~NcursesLibrary()
{
    endwin();
}

bool NcursesLibrary::clearWindow()
{
    clear();
    refresh();
    return true;
}

bool NcursesLibrary::displayWindow()
{
    refresh();
    return true;
}

bool NcursesLibrary::drawCircle(std::pair<int, int> pos, int radius, Color color)
{
    std::pair<int, int> topLeftCorner = pos;
    topLeftCorner.first -= (radius / 2);
    topLeftCorner.second -= (radius / 2);
    return drawRect(topLeftCorner, radius * 2, radius * 2, color);
}

bool NcursesLibrary::drawRect(std::pair<int, int> pos, int width, int height, Color color)
{
    init_pair(1, color.TB, color.TF);
    attron(COLOR_PAIR(1));

    move(pos.first, pos.second);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            addch(' ');
        }
        move(pos.first, pos.second + i);
    }

    attroff(COLOR_PAIR(1));
    reset_color_pairs();
    return true;
}

bool NcursesLibrary::drawText(std::pair<int, int> pos, const std::string &content)
{
    move(pos.first, pos.second);
    printw(content.c_str());
    return true;
}

bool NcursesLibrary::drawEntity(IEntity &entity, std::pair<int, int> pos)
{
    char texture = entity.getTermTexture().first;
    init_pair(1, entity.getTermTexture().second.first, entity.getTermTexture().second.second);
    attron(COLOR_PAIR(1));

    move(pos.first, pos.second);
    for (int i = 0; i < entity.getSize().first; i++) {
        for (int j = 0; j < entity.getSize().second; j++) {
            addch(texture);
        }
        move(pos.first, pos.second + i);
    }

    attroff(COLOR_PAIR(1));
    reset_color_pairs();
    return true;
}

std::string NcursesLibrary::getLibraryName() const
{
    return "Ncurses";
}

Arcade::Evt NcursesLibrary::getInput() const
{
    Arcade::Evt evt;
    int ch = getch();

    switch (ch) {
        case KEY_UP:
            evt.key.key = Arcade::Evt::UP;
            break;
        case KEY_DOWN:
            evt.key.key = Arcade::Evt::DOWN;
            break;
        case KEY_LEFT:
            evt.key.key = Arcade::Evt::LEFT;
            break;
        case KEY_RIGHT:
            evt.key.key = Arcade::Evt::RIGHT;
            break;
    }
    return evt;
}
