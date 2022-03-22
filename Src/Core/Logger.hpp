/*
** EPITECH PROJECT, 2022
** aurele.nicolas@epitech.eu
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "IException.hpp"

class Logger {
    public:
        Logger();
        ~Logger();
        static void log(ArcadeException &exception);

    protected:
    private:
};

#endif /* !LOGGER_HPP_ */
