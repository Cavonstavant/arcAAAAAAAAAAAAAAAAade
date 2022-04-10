/*
** EPITECH PROJECT, 2022
** SdlLibrary.cpp.cc
** File description:
** Created by hjulien,
*/

#include "SdlLibrary.hpp"
#include <iostream>
#include <filesystem>

void SdlLibrary::init()
{
    const std::string font = "Src/GraphicLibs/Resources/Font/ARCADE_N.TTF";
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _window = SDL_CreateWindow("Window",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT,
                               SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    _font = TTF_OpenFont(std::filesystem::absolute(std::filesystem::path(font)).c_str(), 200);
}

void SdlLibrary::close()
{
    TTF_CloseFont(_font);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    SDL_Quit();
}

bool SdlLibrary::clearWindow()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    return true;
}

bool SdlLibrary::displayWindow()
{
    SDL_RenderPresent(_renderer);
    return true;
}

bool SdlLibrary::drawCircle(std::pair<int, int> pos, int radius, Color color)
{
    int diameter = (radius * 2);
    int x = radius - 1;
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y) {
        SDL_RenderDrawPoint(_renderer, GRID_INT(pos.second) + x + 16, GRID_INT(pos.first) - y + 16);
        SDL_RenderDrawPoint(_renderer, GRID_INT(pos.second) + x + 16, GRID_INT(pos.first) + y + 16);
        SDL_RenderDrawPoint(_renderer, GRID_INT(pos.second) - x + 16, GRID_INT(pos.first) - y + 16);
        SDL_RenderDrawPoint(_renderer, GRID_INT(pos.second) - x + 16, GRID_INT(pos.first) + y + 16);
        SDL_RenderDrawPoint(_renderer, GRID_INT(pos.second) + y + 16, GRID_INT(pos.first) - x + 16);
        SDL_RenderDrawPoint(_renderer, GRID_INT(pos.second) + y + 16, GRID_INT(pos.first) + x + 16);
        SDL_RenderDrawPoint(_renderer, GRID_INT(pos.second) - y + 16, GRID_INT(pos.first) - x + 16);
        SDL_RenderDrawPoint(_renderer, GRID_INT(pos.second) - y + 16, GRID_INT(pos.first) + x + 16);
        if (error <= 0) {
            y++;
            error += ty;
            ty += 2;
        }
        if (error > 0) {
            x--;
            tx += 2;
            error += (tx - diameter);
        }
        SDL_SetRenderDrawColor(_renderer, color.R, color.G, color.B, color.A);
    }
}

bool SdlLibrary::drawRect(std::pair<int, int> pos, int width, int height, Color color)
{
    SDL_Rect rect;

    rect.x = GRID_INT(pos.second);
    rect.y = GRID_INT(pos.first);
    rect.w = GRID_INT(width);
    rect.h = GRID_INT(height);

    SDL_SetRenderDrawColor(_renderer, color.R, color.G, color.B, color.A);
    SDL_RenderFillRect(_renderer, &rect);
    return true;
}

bool SdlLibrary::drawText(std::pair<int, int> pos, const std::string &content, Color color)
{
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(_font, content.c_str(), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
    SDL_Rect rect;

    rect.x = GRID_INT(pos.second);
    rect.y = GRID_INT(pos.first);
    rect.w = content.length() * 15;
    rect.h = GRID_INT(1);
    SDL_RenderCopy(_renderer, textTexture, nullptr, &rect);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    return true;
}

bool SdlLibrary::drawEntity(IEntity &entity, std::pair<int, int> pos)
{
    SDL_Texture *texture = IMG_LoadTexture(_renderer, entity.getTexturePath().c_str());
    SDL_Rect rect;

    rect.x = GRID_INT(entity.getPos().second);
    rect.y = GRID_INT(entity.getPos().first);
    rect.w = GRID_INT(entity.getSize().first);
    rect.h = GRID_INT(entity.getSize().second);

    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RenderCopy(_renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    return true;
}

std::string SdlLibrary::getLibraryName() const
{
    return "SDL";
}

Arcade::Evt SdlLibrary::getInput()
{
    SDL_Event event;
    Arcade::Evt evt{};
    Arcade::Evt::KeyEvt keyEvt{};

    if (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT)
            evt.evt_type = Arcade::Evt::WIN_CLOSE;
        else if (event.type == SDL_KEYDOWN) {
            keyEvt.state = true;
            keyEvt.modifier = Arcade::Evt::KEY_MODIFIER_NONE;
            switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                keyEvt.key = 'Q';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_RIGHT:
                keyEvt.key = 'D';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_DOWN:
                keyEvt.key = 'S';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_UP:
                keyEvt.key = 'Z';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_SPACE:
                keyEvt.key = ' ';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_BACKSPACE:
                keyEvt.key = '\b';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_RETURN:
                keyEvt.key = '\n';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_ESCAPE:
                keyEvt.key = 27;
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_a:
                keyEvt.key = 'a';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_b:
                keyEvt.key = 'b';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_c:
                keyEvt.key = 'c';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_d:
                keyEvt.key = 'd';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_e:
                keyEvt.key = 'e';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_f:
                keyEvt.key = 'f';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_g:
                keyEvt.key = 'g';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_h:
                keyEvt.key = 'h';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_i:
                keyEvt.key = 'i';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_j:
                keyEvt.key = 'j';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_k:
                keyEvt.key = 'k';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_l:
                keyEvt.key = 'l';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_m:
                keyEvt.key = 'm';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_n:
                keyEvt.key = 'N';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_o:
                keyEvt.key = 'o';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_p:
                keyEvt.key = 'p';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_q:
                keyEvt.key = 'q';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_r:
                keyEvt.key = 'r';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_s:
                keyEvt.key = 's';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_t:
                keyEvt.key = 't';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_u:
                keyEvt.key = 'u';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_v:
                keyEvt.key = 'v';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_w:
                keyEvt.key = 'w';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_x:
                keyEvt.key = 'x';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_y:
                keyEvt.key = 'y';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            case SDLK_z:
                keyEvt.key = 'z';
                evt.key = keyEvt;
                evt.evt_type = Arcade::Evt::KEY;
                break;
            default:
                break;
            }
        }
    }
    return evt;
}
