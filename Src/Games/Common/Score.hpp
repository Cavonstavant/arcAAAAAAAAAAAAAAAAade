/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Score
*/

#pragma once

#include "Object.hpp"
#include <functional>

/// \class Score class
class Score : public Object {
    public:
        /// \brief Constructor
        Score();
        /// \brief Destructor
        ~Score();
        /// \brief Score getter
        /// \return The score
        unsigned int getScore() const;
        /// \brief Score setter
        /// \param score The new score
        void setScore(unsigned int score);

    protected:
    private:
        unsigned int _score;
};
