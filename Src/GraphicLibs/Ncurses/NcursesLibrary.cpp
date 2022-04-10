/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** NcursesLibrary
*/

#include "NcursesLibrary.hpp"

NcursesLibrary::NcursesLibrary()
{
}

NcursesLibrary::~NcursesLibrary()
{
}

void NcursesLibrary::init()
{
    initscr();
    // if (has_colors())
    //     start_color();
    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    refresh();
}

void NcursesLibrary::close()
{
    curs_set(1);
    endwin();
}

bool NcursesLibrary::clearWindow()
{
    clear();
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

#include <iostream>

bool NcursesLibrary::drawRect(std::pair<int, int> pos, int width, int height, Color color)
{
    init_pair(1, color.TB, color.TF);
    attron(COLOR_PAIR(1));

    // move(pos.first, pos.second);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            mvaddch(pos.first + i, pos.second + j, ' ');
            // addch(' ');
        }
        // move(pos.first, pos.second + i);
    }

    attroff(COLOR_PAIR(1));
    reset_color_pairs();
    return true;
}

bool NcursesLibrary::drawText(std::pair<int, int> pos, const std::string &content, Color color)
{
    init_pair(1, color.TF, color.TB);
    attron(COLOR_PAIR(1));

    move(pos.first, pos.second);
    printw(content.c_str());

    attroff(COLOR_PAIR(1));
    reset_color_pairs();
    return true;
}

bool NcursesLibrary::drawEntity(IEntity &entity, std::pair<int, int> pos)
{
    char texture = entity.getTermTexture().first;
    init_pair(1, entity.getTermTexture().second.first, entity.getTermTexture().second.second);
    attron(COLOR_PAIR(1));

    // move(pos.first, pos.second);
    for (int i = 0; i < entity.getSize().first; i++) {
        for (int j = 0; j < entity.getSize().second; j++) {
            mvaddch(pos.first + i, pos.second + j, texture);
            // addch(texture);
        }
        // move(pos.first, pos.second + i);
    }

    attroff(COLOR_PAIR(1));
    reset_color_pairs();
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
    int ch = getch();

    switch (ch) {
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
