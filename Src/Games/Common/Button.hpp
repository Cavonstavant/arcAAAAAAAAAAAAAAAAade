/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Button
*/

#pragma once

#include "AEntity.hpp"

/// \class Button class
class Button : public AEntity {
public:
    /// \brief Constructor
    Button();
    /// \brief Destructor
    ~Button();
    /// \brief Callback to trigger if the button is clicked
    void (*callback)();
    /// \brief Check if the button is clicked
    bool isClicked(int x, int y);

protected:
private:
};
