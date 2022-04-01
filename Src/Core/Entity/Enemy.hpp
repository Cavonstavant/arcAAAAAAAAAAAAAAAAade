/*
** EPITECH PROJECT, 2022
** Enemy.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_ENEMY_HPP
#define ARCADE_ENEMY_HPP

#include "../../CommonInterface/include/IColor.hpp"
#include "AEntity.hpp"

/// \brief Enemy class inherits from AEntity
class Enemy : public AEntity {
    public:
        /// \brief Constructor with default values : <br>
        /// Default _speed = 0
        /// Default _color = RED
        /// Default _enrage = false
        Enemy();
        /// \brief Destructor override AEntity
        ~Enemy();

        /// \brief Getters & setters
        /// Set the speed of the Enemy Entity
        void setSpeed(int speed);
        /// \brief Set the Color of the Enemy Entity
        void setColor(IColor::COLOR_E color);
        /// \brief Set the enrage boolean of the Enemy Entity
        void setEnrage(bool enrage);
        /// \brief Get the speed of the Enemy Entity
        /// \return Int speed
        int getSpeed() const;
        /// \brief Get the color of the Enemy Entity
        /// \return IColor color
        IColor *getColor() const;
        /// \brief Get the enrage boolean of the Enemy Entity
        /// \return Bool Enrage
        bool getEnrage() const;
        /// \brief Set the isMoving boolean of the Enemy Entity
        void setIsMoving(bool isMoving);
        /// \brief Get the isMoving boolean of the Enemy Entity
        bool getIsMoving() const;

    protected:
    private:
        /// \brief Movement Speed of the Enemy Entity
        int _speed;
        /// \brief IColor of the Enemy Entity. IColor interface used by different Graphics Library
        IColor *_color;
        /// \brief Defines if the Enemy Entity is enrage or not
        bool _enrage;
};

#endif//ARCADE_ENEMY_HPP