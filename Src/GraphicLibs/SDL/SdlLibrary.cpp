/*
** EPITECH PROJECT, 2022
** SdlLibrary.cpp.cc
** File description:
** Created by hjulien,
*/

#include "SdlLibrary.hpp"

SdlLibrary::SdlLibrary()
{
}

SdlLibrary::~SdlLibrary() noexcept
{
}

void SdlLibrary::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Window",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT,
                               SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    _font = TTF_OpenFont("../Resources/Font/ARCADE_N.TTF", 200);
}

void SdlLibrary::close()
{
    TTF_CloseFont(_font);
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

bool SdlLibrary::clearWindow()
{
    return true;
}

bool SdlLibrary::displayWindow()
{
    SDL_RenderPresent(_renderer);
    SDL_Delay(3000);
    return true;
}

bool SdlLibrary::drawCircle(std::pair<int, int> pos, int radius, Color color)
{
    std::pair<int, int> topLeftCorner = pos;

    topLeftCorner.first -= (radius / 2);
    topLeftCorner.second -= (radius / 2);
    return drawRect(topLeftCorner, radius * 2, radius * 2, color);
}

bool SdlLibrary::drawRect(std::pair<int, int> pos, int width, int height, Color color)
{
    SDL_Rect rect;

    rect.x = pos.first;
    rect.y = pos.second;
    rect.w = width;
    rect.h = height;

    SDL_SetRenderDrawColor(_renderer, color.R, color.G, color.B, color.A);
    SDL_RenderFillRect(_renderer, &rect);
    return true;
}

bool SdlLibrary::drawText(std::pair<int, int> pos, const std::string &content)
{
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(_font, content.c_str(), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
    SDL_Rect rect;

    rect.x = pos.first;
    rect.y = pos.second;
    rect.w = (int) (content.length() * 15);
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

    rect.x = entity.getPos().first;
    rect.y = entity.getPos().second;
    rect.w = entity.getSize().first;
    rect.h = entity.getSize().second;

    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RenderCopy(_renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    return true;
}

std::string SdlLibrary::getLibraryName() const
{
    return "SDL";
}

Arcade::Evt SdlLibrary::getInput() const
{
    SDL_Event event;
    Arcade::Evt evt{};
    Arcade::Evt::KeyEvt keyEvt{};

    if (event.type == SDL_QUIT)
        evt.evt_type = Arcade::Evt::WIN_CLOSE;
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            keyEvt.key = 'Q';
            evt.key = keyEvt;
            break;
        case SDLK_RIGHT:
            keyEvt.key = 'D';
            evt.key = keyEvt;
            break;
        case SDLK_DOWN:
            keyEvt.key = 'S';
            evt.key = keyEvt;
            break;
        case SDLK_UP:
            keyEvt.key = 'Z';
            evt.key = keyEvt;
            break;
        case SDLK_SPACE:
            keyEvt.key = ' ';
            evt.key = keyEvt;
            break;
        case SDLK_BACKSPACE:
            keyEvt.key = '\b';
            evt.key = keyEvt;
            break;
        case SDLK_RETURN:
            keyEvt.key = '\n';
            evt.key = keyEvt;
            break;
        case SDLK_ESCAPE:
            keyEvt.key = 27;
            evt.key = keyEvt;
            break;
        case SDLK_a:
            keyEvt.key = 'a';
            evt.key = keyEvt;
            break;
        case SDLK_b:
            keyEvt.key = 'b';
            evt.key = keyEvt;
            break;
        case SDLK_c:
            keyEvt.key = 'c';
            evt.key = keyEvt;
            break;
        case SDLK_d:
            keyEvt.key = 'd';
            evt.key = keyEvt;
            break;
        case SDLK_e:
            keyEvt.key = 'e';
            evt.key = keyEvt;
            break;
        case SDLK_f:
            keyEvt.key = 'f';
            evt.key = keyEvt;
            break;
        case SDLK_g:
            keyEvt.key = 'g';
            evt.key = keyEvt;
            break;
        case SDLK_h:
            keyEvt.key = 'h';
            evt.key = keyEvt;
            break;
        case SDLK_i:
            keyEvt.key = 'i';
            evt.key = keyEvt;
            break;
        case SDLK_j:
            keyEvt.key = 'j';
            evt.key = keyEvt;
            break;
        case SDLK_k:
            keyEvt.key = 'k';
            evt.key = keyEvt;
            break;
        case SDLK_l:
            keyEvt.key = 'l';
            evt.key = keyEvt;
            break;
        case SDLK_m:
            keyEvt.key = 'm';
            evt.key = keyEvt;
            break;
        case SDLK_n:
            keyEvt.key = 'N';
            evt.key = keyEvt;
            break;
        case SDLK_o:
            keyEvt.key = 'o';
            evt.key = keyEvt;
            break;
        case SDLK_p:
            keyEvt.key = 'p';
            evt.key = keyEvt;
            break;
        case SDLK_q:
            keyEvt.key = 'q';
            evt.key = keyEvt;
            break;
        case SDLK_r:
            keyEvt.key = 'r';
            evt.key = keyEvt;
            break;
        case SDLK_s:
            keyEvt.key = 's';
            evt.key = keyEvt;
            break;
        case SDLK_t:
            keyEvt.key = 't';
            evt.key = keyEvt;
            break;
        case SDLK_u:
            keyEvt.key = 'u';
            evt.key = keyEvt;
            break;
        case SDLK_v:
            keyEvt.key = 'v';
            evt.key = keyEvt;
            break;
        case SDLK_w:
            keyEvt.key = 'w';
            evt.key = keyEvt;
            break;
        case SDLK_x:
            keyEvt.key = 'x';
            evt.key = keyEvt;
            break;
        case SDLK_y:
            keyEvt.key = 'y';
            evt.key = keyEvt;
            break;
        case SDLK_z:
            keyEvt.key = 'z';
            evt.key = keyEvt;
            break;
        default:
            break;
        }
    }
}
