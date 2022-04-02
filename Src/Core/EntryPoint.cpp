/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** EntryPoint
*/

#include "Core.hpp"
#include "../GraphicLibs/SDL/SdlLibrary.hpp"
#include "../GraphicLibs/SFML/SfmlLibrary.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    /*SdlLibrary library;

    library.displayWindow();
    library.clearWindow();*/

    SfmlLibrary library;
    Color color(0, 0, 0, 255);
    std::pair<int, int> pos;
    pos.first = 100;
    pos.second = 100;

    while (true) {
        library.displayWindow();
        library.drawRect(pos, 100, 100, color);
    }
    library.clearWindow();
    return (0);
}
