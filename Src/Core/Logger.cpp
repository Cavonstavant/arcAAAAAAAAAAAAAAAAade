/*
** EPITECH PROJECT, 2022
** aurele.nicolas@epitech.eu
** File description:
** Logger
*/

#include "Logger.hpp"
#include "Exception.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

ArcadeException Logger::log(ArcadeException ex)
{
    std::stringstream ssColor;
    std::stringstream ss;
    std::ofstream ofLog;

    ssColor << COLOR_RED << "[LOGGER] " << COLOR_BOLD << ex.getName() << COLOR_RESET << " >> " << COLOR_BOLD << ex.what() << COLOR_RESET << std::endl;
    ssColor << COLOR_RED << ">> " << COLOR_BOLD << ex.getFunc() << COLOR_RESET << " (" << ex.getFile() << ":" << ex.getLine() << ")" << std::endl;
    std::cerr << ssColor.str() << std::endl;

    try {
        ss << "[LOGGER] " << ex.getName() << " >> " << ex.what() << std::endl;
        ss << ">> " << ex.getFunc() << " (" << ex.getFile() << ":" << ex.getLine() << ")" << std::endl;
        ofLog.open("arcade.log", std::ios::app);
        ofLog << ss.str();
        ofLog.close();
    } catch (std::exception &e) {
        std::cerr << "Logging into 'arcade.log' file failed (" << e.what() << ")" << std::endl;
    }
    return ex;
}

bool Logger::ENABLED()
{
    return true;
}

bool Logger::DISABLED()
{
    return false;
}
