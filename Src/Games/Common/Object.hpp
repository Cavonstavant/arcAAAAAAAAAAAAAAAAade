/*
** EPITECH PROJECT, 2022
** Object.hpp.h
** File description:
** Created by hjulien,
*/

/// \file Src/Games/Common/Object.hpp

#ifndef ARCADE_OBJECT_HPP
#define ARCADE_OBJECT_HPP

#include "../../CommonInterface/include/Color.hpp"
#include "AEntity.hpp"

/// \brief Object class represents all the Entity not moving. Like walls, fruits.
class Object : public AEntity {
    public:
        /// \brief Deleted constructor, you must inform the type of object
        Object() = delete;
        /// \brief Constructor with the type of the object you want to create
        explicit Object(ENTITY_TYPE type);
        /// \brief Destructor
        ~Object();

        /// \brief Set the Entity boolean _isMoving
        void setIsMoving(bool isMoving) override;
        /// \brief Get the Entity boolean _isMoving
        /// \return false in any case;
        [[nodiscard]] bool getIsMoving() const override;
        /// \brief Set the Color of the Enemy Entity
        void setColor(Color color);
        /// \brief Get the color of the Enemy Entity
        /// \return IColor color
        [[nodiscard]] Color getColor() const;
        /// \brief Set the _type
        void setType(ENTITY_TYPE type);
        /// \brief Get the _type
        /// \return The TYPE_E _type of the Object
        [[nodiscard]] ENTITY_TYPE getType() const;

    private:
        Color _color{};
        ENTITY_TYPE _type;
};


#endif//ARCADE_OBJECT_HPP
