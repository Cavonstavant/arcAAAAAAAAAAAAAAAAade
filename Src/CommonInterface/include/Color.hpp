/*
** EPITECH PROJECT, 2022
** Color.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_COLOR_HPP
#define ARCADE_COLOR_HPP

#include <cstddef>

/// \brief Color structure
struct Color {
        Color() = default;
        Color(char r, char g, char b, char a)
        {
            _r = r;
            _g = g;
            _b = b;
            _a = a;
        };
        ~Color() = default;
        int _r;
        int _g;
        int _b;
        int _a;
};


#endif//ARCADE_COLOR_HPP
