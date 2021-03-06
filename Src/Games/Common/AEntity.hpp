/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** AEntity
*/

/// \file Src/Games/Common/AEntity.hpp

#ifndef AENTITY_HPP_
#define AENTITY_HPP_

#include "../../CommonInterface/include/IEntity.hpp"
#include <string>

/// \brief Entity Abstract class
class AEntity : public IEntity {
    public:
        /// \brief Default Constructor
        AEntity();
        /// \brief Destructor
        ~AEntity() = default;

        /// \brief Get the entity position
        /// \return The std::pair<int, int> position
        std::pair<int, int> getPos() const override;

        /// \brief Set the entity position
        /// \param Pos the std::pair<int, int> position
        void setPos(std::pair<int, int> pos) override;

        /// \brief Get the entity size
        /// \return The std::pair<int, int> size
        std::pair<int, int> getSize() const override;

        /// \brief Set the entity size
        /// \param Size the std::pair<int, int> size
        void setSize(std::pair<int, int> size) override;

        /// \brief Set the Entity boolean isMoving
        virtual void setIsMoving(bool isMoving) = 0;

        /// \brief Get the Entity boolean isMoving
        /// \return bool isMoving;
        virtual bool getIsMoving() const = 0;

        /// \brief Set the texturePath of the entity
        /// \param std::string texturePath represents the path to find the texture
        void setTexturePath(std::string texturePath) override;

        /// \brief Get the texturePAth of the Entity
        /// \return the path to the texture
        std::string getTexturePath(void) const override;

        /// \brief Set the entity char and color to replace textures for terminal graphical libraries
        /// \param char c the char to replace the texture
        /// \param Color::TermColors fg the foreground color of the char
        /// \param Color::TermColors bg the background color of the char
        void setTermTexture(char c, Color::TermColors fg, Color::TermColors bg) override;

        /// \brief Get the entity char and color to replace textures for terminal graphical libraries
        /// \return the char and colors of the entity for the terminal graphical libraries
        std::pair<char, std::pair<Color::TermColors, Color::TermColors>> getTermTexture(void) const override;

        /// \brief Get the Entity direction
        /// \return the direction of the entity
        Direction getDirection() const override;

        /// \brief Set the Entity direction
        /// \param direction the direction of the entity
        void setDirection(Direction direction) override;

        void setType(ENTITY_TYPE type) override;
        ENTITY_TYPE getType() const override;

    protected:
        std::pair<int, int> _pos;
        std::pair<int, int> _size;
        bool _isMoving;
        std::string _texturePath;
        std::pair<char, std::pair<Color::TermColors, Color::TermColors>> _termTexture;
        Direction _direction;
        ENTITY_TYPE _type;

    private:
};

#endif /* !AENTITY_HPP_ */
