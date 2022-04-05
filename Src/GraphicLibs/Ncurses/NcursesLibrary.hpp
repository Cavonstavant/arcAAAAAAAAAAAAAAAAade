/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** NcursesLibrary
*/

#ifndef ARCADE_NCURSESLIBRARY_HPP
#define ARCADE_NCURSESLIBRARY_HPP

#include "../../CommonInterface/include/IGraph.hpp"
#include <ncurses.h>

/// \brief NCURSES library using int as template value from IGraph
class NcursesLibrary : public IGraph<int> {
    public:
        /// \brief Constructor
        NcursesLibrary();

        /// \brief Destructor
        ~NcursesLibrary();

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
};


#endif//ARCADE_NCURSESLIBRARY_HPP
