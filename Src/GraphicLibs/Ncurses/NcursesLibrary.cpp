/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** NcursesLibrary
*/

#include "NcursesLibrary.hpp"
#include <iostream>

NcursesLibrary::NcursesLibrary()
{
}

NcursesLibrary::~NcursesLibrary()
{
}

void NcursesLibrary::init()
{

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    refresh();
    if (has_colors())
        start_color();
    nodelay(stdscr, TRUE);
    _colors = 0;
}

void NcursesLibrary::close()
{

    clear();
    endwin();
    // curs_set(1);
    // endwin();
}

bool NcursesLibrary::clearWindow()
{
    clear();
    reset_color_pairs();
    _colors = 0;
    return true;
}

bool NcursesLibrary::displayWindow()
{
    refresh();
    napms(500);
    return true;
}

bool NcursesLibrary::drawCircle(std::pair<int, int> pos, int radius, Color color)
{
    init_pair(_colors, color.TF, color.TB);
    attron(COLOR_PAIR(_colors));

    if (radius <= 5)
        mvaddch(pos.first, pos.second, '.');
    else
        mvaddch(pos.first, pos.second, '*');

    attroff(COLOR_PAIR(_colors));
    _colors++;
    return true;
}

bool NcursesLibrary::drawRect(std::pair<int, int> pos, int width, int height, Color color)
{
    init_pair(_colors, color.TF, color.TB);
    attron(COLOR_PAIR(_colors));

    for (int i = pos.first; i < pos.first + height; i++) {
        for (int j = pos.second; j < pos.second + width; j++) {
            mvaddch(i, j, 'X');
        }
    }

    attroff(COLOR_PAIR(_colors));
    _colors++;
    return true;
}

bool NcursesLibrary::drawText(std::pair<int, int> pos, const std::string &content, Color color)
{
    init_pair(_colors, color.TF, color.TB);
    attron(COLOR_PAIR(_colors));

    move(pos.first, pos.second);
    printw(content.c_str());

    attroff(COLOR_PAIR(_colors));
    _colors++;
    return true;
}

bool NcursesLibrary::drawEntity(IEntity &entity, std::pair<int, int> pos)
{
    char texture = entity.getTermTexture().first;
    init_pair(_colors, entity.getTermTexture().second.first, entity.getTermTexture().second.second);
    attron(COLOR_PAIR(_colors));

    for (int i = pos.first; i < pos.first + entity.getSize().first; i++) {
        for (int j = pos.second; j < pos.second + entity.getSize().second; j++) {
            mvaddch(i, j, texture);
        }
    }

    attroff(COLOR_PAIR(_colors));
    _colors++;
    return true;
}

std::string NcursesLibrary::getLibraryName() const
{
    return "Ncurses";
}

Arcade::Evt NcursesLibrary::getInput()
{
    Arcade::Evt evt{};
    Arcade::Evt::KeyEvt keyEvt{};
    // timeout(0);
    int key = getch();

    if (key == ERR) {
        evt.evt_type = Arcade::Evt::NONE;
        return evt;
    }

    switch (key) {
        case KEY_LEFT:
            keyEvt.key = 'Q';
            evt.key = keyEvt;
            break;
        case KEY_RIGHT:
            keyEvt.key = 'D';
            evt.key = keyEvt;
            break;
        case KEY_DOWN:
            keyEvt.key = 'S';
            evt.key = keyEvt;
            break;
        case KEY_UP:
            keyEvt.key = 'Z';
            evt.key = keyEvt;
            break;
        case ' ':
            keyEvt.key = ' ';
            evt.key = keyEvt;
            break;
        case KEY_BACKSPACE:
            keyEvt.key = '\b';
            evt.key = keyEvt;
            break;
        case KEY_ENTER:
            keyEvt.key = '\n';
            evt.key = keyEvt;
            break;
        case 27:
            keyEvt.key = 27;
            evt.key = keyEvt;
            break;
        case 'A':
        case 'a':
            keyEvt.key = 'a';
            evt.key = keyEvt;
            break;
        case 'B':
        case 'b':
            keyEvt.key = 'b';
            evt.key = keyEvt;
            break;
        case 'C':
        case 'c':
            keyEvt.key = 'c';
            evt.key = keyEvt;
            break;
        case 'D':
        case 'd':
            keyEvt.key = 'd';
            evt.key = keyEvt;
            break;
        case 'E':
        case 'e':
            keyEvt.key = 'e';
            evt.key = keyEvt;
            break;
        case 'F':
        case 'f':
            keyEvt.key = 'f';
            evt.key = keyEvt;
            break;
        case 'G':
        case 'g':
            keyEvt.key = 'g';
            evt.key = keyEvt;
            break;
        case 'H':
        case 'h':
            keyEvt.key = 'h';
            evt.key = keyEvt;
            break;
        case 'I':
        case 'i':
            keyEvt.key = 'i';
            evt.key = keyEvt;
            break;
        case 'J':
        case 'j':
            keyEvt.key = 'j';
            evt.key = keyEvt;
            break;
        case 'K':
        case 'k':
            keyEvt.key = 'k';
            evt.key = keyEvt;
            break;
        case 'L':
        case 'l':
            keyEvt.key = 'l';
            evt.key = keyEvt;
            break;
        case 'M':
        case 'm':
            keyEvt.key = 'm';
            evt.key = keyEvt;
            break;
        case 'N':
        case 'n':
            keyEvt.key = 'N';
            evt.key = keyEvt;
            break;
        case 'O':
        case 'o':
            keyEvt.key = 'o';
            evt.key = keyEvt;
            break;
        case 'P':
        case 'p':
            keyEvt.key = 'p';
            evt.key = keyEvt;
            break;
        case 'Q':
        case 'q':
            keyEvt.key = 'q';
            evt.key = keyEvt;
            break;
        case 'R':
        case 'r':
            keyEvt.key = 'r';
            evt.key = keyEvt;
            break;
        case 'S':
        case 's':
            keyEvt.key = 's';
            evt.key = keyEvt;
            break;
        case 'T':
        case 't':
            keyEvt.key = 't';
            evt.key = keyEvt;
            break;
        case 'U':
        case 'u':
            keyEvt.key = 'u';
            evt.key = keyEvt;
            break;
        case 'V':
        case 'v':
            keyEvt.key = 'v';
            evt.key = keyEvt;
            break;
        case 'W':
        case 'w':
            keyEvt.key = 'w';
            evt.key = keyEvt;
            break;
        case 'X':
        case 'x':
            keyEvt.key = 'x';
            evt.key = keyEvt;
            break;
        case 'Y':
        case 'y':
            keyEvt.key = 'y';
            evt.key = keyEvt;
            break;
        case 'Z':
        case 'z':
            keyEvt.key = 'z';
            evt.key = keyEvt;
            break;
        default:
            break;
    }
    return evt;
}
