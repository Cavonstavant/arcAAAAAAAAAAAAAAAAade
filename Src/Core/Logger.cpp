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
        ofLog << ss.str() << std::endl;
        ofLog.close();
    } catch (std::exception &e) {
        std::cerr << "Logging into 'arcade.log' file failed (" << e.what() << ")" << std::endl;
    }
    return ex;
}

ArcadeInfo Logger::log(ArcadeInfo info)
{
    std::stringstream ssColor;
    std::stringstream ss;
    std::ofstream ofLog;

    ssColor << COLOR_BLUE << "[INFO] " << COLOR_BOLD << info.getName() << COLOR_RESET << " >> " << COLOR_BOLD << info.what() << COLOR_RESET << std::endl;
    ssColor << COLOR_BLUE << ">> " << COLOR_BOLD << info.getFunc() << COLOR_RESET << " (" << info.getFile() << ":" << info.getLine() << ")" << std::endl;
    std::cerr << ssColor.str() << std::endl;

    try {
        ss << "[INFO] " << info.getName() << " >> " << info.what() << std::endl;
        ss << ">> " << info.getFunc() << " (" << info.getFile() << ":" << info.getLine() << ")" << std::endl;
        ofLog.open("arcade.log", std::ios::app);
        ofLog << ss.str() << std::endl;
        ofLog.close();
    } catch (std::exception &e) {
        std::cerr << "Logging into 'arcade.log' file failed (" << e.what() << ")" << std::endl;
    }
    return info;
}

bool Logger::ENABLED()
{
    return true;
}

bool Logger::DISABLED()
{
    return false;
}
