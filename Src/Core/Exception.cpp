/*
** EPITECH PROJECT, 2022
** aurele.nicolas@epitech.eu
** File description:
** Exception
*/

#include "Exception.hpp"
#include <iostream>
#include <string>
#include <sstream>

ArcadeException::ArcadeException(std::string const &what, std::string const &func, int const &line, std::string const &file) : _name("ArcadeException")
{
    std::stringstream ss;

    _what = what;
    _func = func;
    _line = line;
    _file = file;

    ss << func << " (" << file << ":" << line << ")";
    _where = ss.str();
}

const char *ArcadeException::what() const noexcept
{
    return _what.c_str();
}

const std::string &ArcadeException::where() const noexcept
{
    return _where;
}

const std::string &ArcadeException::getFunc() const noexcept
{
    return _func;
}

const std::string &ArcadeException::getFile() const noexcept
{
    return _file;
}

const int &ArcadeException::getLine() const noexcept
{
    return _line;
}

const std::string &ArcadeException::getName() const noexcept
{
    return _name;
}
