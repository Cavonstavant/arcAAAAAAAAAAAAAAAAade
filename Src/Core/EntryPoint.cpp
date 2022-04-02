/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** EntryPoint
*/

#include "Core.hpp"
#include "../GraphicLibs/SDL/SdlLibrary.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    SdlLibrary library;

    library.displayWindow();
    library.clearWindow();
    return (0);
}
