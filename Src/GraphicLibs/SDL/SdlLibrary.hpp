/*
** EPITECH PROJECT, 2022
** SdlLibrary.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_SDLLIBRARY_HPP
#define ARCADE_SDLLIBRARY_HPP

#include "../../CommonInterface/include/IGraph.hpp"
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

/// \brief SDL Library using int as template value from IGraph
class SdlLibrary : public IGraph<int> {
public:
    /// \brief Default Constructor
    SdlLibrary();

    /// \brief Default Destructor
    ~SdlLibrary() noexcept;

    bool clearWindow() override;
    bool displayWindow() override;

    bool drawCircle(std::pair<int, int> pos, int radius,
                    Color color) override;
    bool drawRect(std::pair<int, int> pos, int width, int height,
                  Color color) override;
    bool drawText(std::pair<int, int> pos,
                  const std::string &content) override;
    bool drawEntity(IEntity &entity,
                    std::pair<int, int> pos) override;
private:
    /// \brief SDL window using to display every entities. Centered Window by default
    SDL_Window *_window;

    /// \brief SDL renderer using to render to the window what to display
    SDL_Renderer *_renderer;
};


#endif //ARCADE_SDLLIBRARY_HPP
