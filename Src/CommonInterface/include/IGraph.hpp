/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** IDisplay
*/

#ifndef ARCADE_IDISPLAY_HPP
#define ARCADE_IDISPLAY_HPP

#include "Color.hpp"
#include "IEntity.hpp"
#include <string>

#ifndef GRID_INT
#define GRID_INT(x) x * 32
#endif
#ifndef GRID_PAIR
#define GRID_PAIR(x) std::make_pair(GRID_INT(x.first), GRID_INT(x.second))
#endif

/// \brief represents a generic graphical library
class IGraph {

    public:
        /// \brief Destructor
        virtual ~IGraph() = default;

        /// \brief Create a circle, set position, set radius, then display it on the
        /// window. After all destroy the Circle \param pos the std::pair<int,int>
        /// position \param radius represents the radius of the circle \param
        /// represents the struct color (r, g, b, a) of the Circle \return true if the
        /// circle is successfully draw
        virtual bool drawCircle(std::pair<int, int> pos, int radius, Color color) = 0;

        /// \brief Create a Rectangle, set position, set width & height, then display
        /// it on the window. After all destroy the Rectangle \param pos the
        /// std::pair<int, int> position \param height for the height of the rectangle
        /// \param width for the width of the rectangle
        /// \param represents the struct color (r, g, b, a) of the Rectangle
        /// \return true if the rectangle is successfully draw
        virtual bool drawRect(std::pair<int, int> pos, int width, int height,
                              Color color) = 0;

        /// \brief Create a text, set position, set content, set font, then display it
        /// on the window. After all destroy the Text \param pos the std::pair<int,
        /// int> position \param content the std::string content \return true if the
        /// text is successfully draw
        virtual bool drawText(std::pair<int, int> pos,
                              const std::string &content) = 0;

        /// \brief Create an Entity, set position, then display it on the window.
        /// After all destroy the Entity \param IEntity representing the entity with
        /// its own properties \param std::pair<int, int> pos to know where to display
        /// the entity in the window \return true if the entity is successfully draw
        virtual bool drawEntity(IEntity &entity, std::pair<int, int> pos) = 0;

        /// \brief clear the window
        /// \return true if the window is successfully cleared
        virtual bool clearWindow() = 0;

        /// \brief display the window
        /// \return true if the window is successfully displayed
        virtual bool displayWindow() = 0;

        /// \brief get the graphical lib
        virtual std::string getName() const = 0;

    protected:
    private:
};

#endif// ARCADE_IDISPLAY_HPP
