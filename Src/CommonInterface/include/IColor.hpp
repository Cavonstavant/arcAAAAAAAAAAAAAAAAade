/*
** EPITECH PROJECT, 2022
** IColor.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_ICOLOR_HPP
#define ARCADE_ICOLOR_HPP

/// \brief Color interface for entities.
class IColor {
    public:
        /// \brief Enum of standard colors
        enum COLOR_E {
            RED,
            YELLOW,
            BLUE,
            ORANGE
        };
        /// \brief Destructor
        virtual ~IColor() = default;
        /// \brief Getter & Setter
        /// \brief Set the color
        /// \param COLOR_E color
        virtual void setColor(const COLOR_E color) = 0;
        /// \brief Get the color
        /// \return IColor
        virtual IColor *getColor() const = 0;

    protected:
    private:
};


#endif//ARCADE_ICOLOR_HPP
