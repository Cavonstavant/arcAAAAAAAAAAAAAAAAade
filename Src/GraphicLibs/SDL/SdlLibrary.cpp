/*
** EPITECH PROJECT, 2022
** SdlLibrary.cpp.cc
** File description:
** Created by hjulien,
*/

#include "SdlLibrary.hpp"

SdlLibrary::SdlLibrary()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Window",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH, WINDOW_HEIGHT,
                               SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
}

SdlLibrary::~SdlLibrary() noexcept
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

bool SdlLibrary::clearWindow()
{
    SDL_RenderClear(_renderer);
    return true;
}

bool SdlLibrary::displayWindow()
{
    SDL_SetWindowDisplayMode(_window, NULL);
    //TODO DELETE THIS
    SDL_Delay(3000);
    return true;
}

bool SdlLibrary::drawCircle(std::pair<int, int> pos, int radius, Color color)
{
    return true;
}

bool SdlLibrary::drawRect(std::pair<int, int> pos, int width, int height, Color color)
{
    return true;
}

bool SdlLibrary::drawText(std::pair<int, int> pos, const std::string &content)
{
    return true;
}

bool SdlLibrary::drawEntity(IEntity &entity, std::pair<int, int> pos)
{
    return true;
}
