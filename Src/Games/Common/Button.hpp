/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Button
*/

/// \file Src/Games/Common/Button.hpp

#pragma once

#include "Object.hpp"
#include <functional>

/// \class Button class
/// \brief Represents a button object
class Button : public Object {
    public:
        /// \brief Constructor
        Button(std::function<void()> callback, std::string actionString = "");
        /// \brief Destructor
        ~Button();
        /// \brief Callback to trigger if the button is clicked
        std::function<void()> callback;
        /// \brief Check if the button is clicked
        bool isClicked(int x, int y);

    protected:
    private:
        std::string _actionString;
};
