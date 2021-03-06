/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** NcursesLibrary
*/

/// \file Src/GraphicLibs/Ncurses/NcursesLibrary.hpp

#ifndef ARCADE_NCURSESLIBRARY_HPP
#define ARCADE_NCURSESLIBRARY_HPP

#include "../../CommonInterface/include/IGraph.hpp"
#include "Event.hpp"
#include <ncurses.h>

/// \brief NCURSES library using int as template value from IGraph
class NcursesLibrary : public IGraph {
    public:
        /// \brief Constructor (calls initscr)
        NcursesLibrary();

        /// \brief Destructor (calls endscr)
        ~NcursesLibrary();

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

        std::string getLibraryName() const override final;
        Arcade::Evt getInput();

    private:
        int _colors;
};

#endif//ARCADE_NCURSESLIBRARY_HPP
