/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include "Color.hpp"
#include <string>

/// \brief represents a generic entity within the game
class IEntity {
    public:
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        /// \brief Destructor
        ~IEntity() = default;
        virtual std::pair<int, int> getPos() const = 0;
        /// \brief Set the entity position
        /// \param pos the std::pair<int, int> position
        virtual void setPos(std::pair<int, int> pos) = 0;
        /// \brief Get the entity size
        /// \return the std::pair<int, int> size
        virtual std::pair<int, int> getSize() const = 0;
        /// \brief Set the entity size
        /// \param size the std::pair<int, int> size
        virtual void setSize(std::pair<int, int> size) = 0;
        /// \brief Set the texturePath of the entity
        /// \param std::string texturePath represents the path to find the texture
        virtual void setTexturePath(std::string texturePath) = 0;
        /// \brief Get the texturePAth of the Entity
        /// \return the path to the texture
        virtual std::string getTexturePath(void) const = 0;
        /// \brief Set the entity char and color to replace textures for terminal graphical libraries
        /// \param char c the char to replace the texture
        /// \param Color::TermColors fg the foreground color of the char
        /// \param Color::TermColors bg the background color of the char
        virtual void setTermTexture(char c, Color::TermColors fg, Color::TermColors bg) = 0;
        /// \brief Get the entity char and color to replace textures for terminal graphical libraries
        /// \return the char and colors of the entity for the terminal graphical libraries
        virtual std::pair<char, std::pair<Color::TermColors, Color::TermColors>> getTermTexture(void) const = 0;
        /// \brief Get the Entity direction
        /// \return the direction of the entity
        virtual Direction getDirection() const = 0;
        /// \brief Set the Entity direction
        /// \param direction the direction of the entity
        virtual void setDirection(Direction direction) = 0;

};

#endif /* !IENTITY_HPP_ */
