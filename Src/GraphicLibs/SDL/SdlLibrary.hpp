/*
** EPITECH PROJECT, 2022
** SdlLibrary.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_SDLLIBRARY_HPP
#define ARCADE_SDLLIBRARY_HPP

#include "Event.hpp"
#include "IGraph.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/// \brief SDL Library
class SdlLibrary : public IGraph {
public:
    /// \brief Default Constructor
    /// SDL_INIT_EVERYTHING | Initialize every feature like video, audio, events...
    /// Creating & Initializing Window & Renderer
    /// Loading member _font (ARCADE_N.TTF as default font)
    SdlLibrary() = default;

    /// \brief Default Destructor
    /// Destroying Window & Renderer
    /// SDL_Quit() to close every features previously opened in the constructor
    ~SdlLibrary() override = default;

    /// \brief Initialize the library
    void init() override;
    /// \brief Closes the library
    void close() override;

    bool clearWindow() override;
    bool displayWindow() override;

    bool drawCircle(std::pair<int, int> pos, int radius,
                    Color color) override;
    bool drawRect(std::pair<int, int> pos, int width, int height,
                  Color color) override;
    bool drawText(std::pair<int, int> pos,
                  const std::string &content,
                  Color color) override;
    bool drawEntity(IEntity &entity,
                    std::pair<int, int> pos) override;
    Arcade::Evt getInput() override;
    std::string getLibraryName() const override;

private:
    /// \brief SDL window using to display every entities. Centered Window by default, with a size of DEFAULT_WINDOW_WIDTH(width) x DEFAULT_WINDOW_HEIGHT(height) by default.
    SDL_Window *_window;

    /// \brief SDL renderer using to render to the window what to display
    SDL_Renderer *_renderer;

    /// \brief SDL font represents default font for the library
    TTF_Font *_font;
};

#endif//ARCADE_SDLLIBRARY_HPP
