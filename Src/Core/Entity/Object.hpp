/*
** EPITECH PROJECT, 2022
** Object.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_OBJECT_HPP
#define ARCADE_OBJECT_HPP

#include "../../CommonInterface/include/Color.hpp"
#include "AEntity.hpp"

/// \brief Object class represents all the Entity not moving. Like walls, fruits.
class Object : public AEntity {
public:
    enum TYPE_E {
        WALL,
        FRUITS,
        POINTS,
        ENUM_SIZE
    };
    /// \brief Constructor
    Object();
    /// \brief Destructor
    ~Object();

    /// \brief Set the Entity boolean _isMoving
    void setIsMoving(bool isMoving) override;
    /// \brief Get the Entity boolean _isMoving
    /// \return false in any case;
    bool getIsMoving() const override;
    /// \brief Set the Color of the Enemy Entity
    void setColor(Color color);
    /// \brief Get the color of the Enemy Entity
    /// \return IColor color
    Color getColor() const;
    /// \brief Set the _type
    void setType(const TYPE_E type);
    /// \brief Get the _type
    /// \return The TYPE_E _type of the Object
    TYPE_E getType() const;

private:
    Color _color;
    TYPE_E _type;
};


#endif//ARCADE_OBJECT_HPP
