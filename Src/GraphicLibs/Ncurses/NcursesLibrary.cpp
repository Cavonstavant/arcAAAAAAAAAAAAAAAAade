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
        mvaddch(pos.first, pos.second, (char)102 | A_ALTCHARSET);
    else
        mvaddch(pos.first, pos.second, (char)96 | A_ALTCHARSET);

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
            if (i == pos.first ||
                j == pos.second ||
                i == pos.first + height - 1 ||
                j == pos.second + width - 1)
                mvaddch(i, j, ACS_CKBOARD);
            else
                mvaddch(i, j, ' ');
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
            mvaddch(i, j, texture | A_ALTCHARSET);
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
    int key = getch();

    if (key == ERR) {
        evt.evt_type = Arcade::Evt::NONE;
        return evt;
    }

    switch (key) {
        case KEY_LEFT:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'Q';
            evt.key = keyEvt;
            break;
        case KEY_RIGHT:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'D';
            evt.key = keyEvt;
            break;
        case KEY_DOWN:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'S';
            evt.key = keyEvt;
            break;
        case KEY_UP:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'Z';
            evt.key = keyEvt;
            break;
        case ' ':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = ' ';
            evt.key = keyEvt;
            break;
        case KEY_BACKSPACE:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '\b';
            evt.key = keyEvt;
            break;
        case KEY_ENTER:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '\n';
            evt.key = keyEvt;
            break;
        case 27:
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 27;
            evt.key = keyEvt;
            break;
        case 'A':
        case 'a':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'a';
            evt.key = keyEvt;
            break;
        case 'B':
        case 'b':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'b';
            evt.key = keyEvt;
            break;
        case 'C':
        case 'c':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'c';
            evt.key = keyEvt;
            break;
        case 'D':
        case 'd':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'd';
            evt.key = keyEvt;
            break;
        case 'E':
        case 'e':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'e';
            evt.key = keyEvt;
            break;
        case 'F':
        case 'f':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'f';
            evt.key = keyEvt;
            break;
        case 'G':
        case 'g':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'g';
            evt.key = keyEvt;
            break;
        case 'H':
        case 'h':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'h';
            evt.key = keyEvt;
            break;
        case 'I':
        case 'i':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'i';
            evt.key = keyEvt;
            break;
        case 'J':
        case 'j':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'j';
            evt.key = keyEvt;
            break;
        case 'K':
        case 'k':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'k';
            evt.key = keyEvt;
            break;
        case 'L':
        case 'l':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'l';
            evt.key = keyEvt;
            break;
        case 'M':
        case 'm':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'm';
            evt.key = keyEvt;
            break;
        case 'N':
        case 'n':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'N';
            evt.key = keyEvt;
            break;
        case 'O':
        case 'o':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'o';
            evt.key = keyEvt;
            break;
        case 'P':
        case 'p':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'p';
            evt.key = keyEvt;
            break;
        case 'Q':
        case 'q':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'q';
            evt.key = keyEvt;
            break;
        case 'R':
        case 'r':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'r';
            evt.key = keyEvt;
            break;
        case 'S':
        case 's':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 's';
            evt.key = keyEvt;
            break;
        case 'T':
        case 't':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 't';
            evt.key = keyEvt;
            break;
        case 'U':
        case 'u':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'u';
            evt.key = keyEvt;
            break;
        case 'V':
        case 'v':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'v';
            evt.key = keyEvt;
            break;
        case 'W':
        case 'w':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'w';
            evt.key = keyEvt;
            break;
        case 'X':
        case 'x':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'x';
            evt.key = keyEvt;
            break;
        case 'Y':
        case 'y':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'y';
            evt.key = keyEvt;
            break;
        case 'Z':
        case 'z':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = 'z';
            evt.key = keyEvt;
            break;
        case '0':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '0';
            evt.key = keyEvt;
            break;
        case '1':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '1';
            evt.key = keyEvt;
            break;
        case '2':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '2';
            evt.key = keyEvt;
            break;
        case '3':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '3';
            evt.key = keyEvt;
            break;
        case '4':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '4';
            evt.key = keyEvt;
            break;
        case '5':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '5';
            evt.key = keyEvt;
            break;
        case '6':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '6';
            evt.key = keyEvt;
            break;
        case '7':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '7';
            evt.key = keyEvt;
            break;
        case '8':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '8';
            evt.key = keyEvt;
            break;
        case '9':
            evt.evt_type = Arcade::Evt::KEY;
            keyEvt.key = '9';
            evt.key = keyEvt;
            break;
        default:
            break;
    }
    return evt;
}
