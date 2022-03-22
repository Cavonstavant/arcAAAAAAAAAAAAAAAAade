/*
** EPITECH PROJECT, 2022
** Project
** File description:
** entryPoint
*/

#include "Exception.hpp"
#include <iostream>

int main(void)
{
    try {
        throw ArcadeEX("Error");
    } catch (ArcadeException &ex) {
        std::cout << "EXCEPTION " << ex.getName() << std::endl;
        std::cout << "WHAT : " << ex.what() << std::endl;
        std::cout << "WHERE: " << ex.where() << std::endl;
    }
    std::cout << std::endl;
    try {
        throw FactoryEX("Error");
    } catch (ArcadeException &ex) {
        std::cout << "EXCEPTION " << ex.getName() << std::endl;
        std::cout << "WHAT : " << ex.what() << std::endl;
        std::cout << "WHERE: " << ex.where() << std::endl;
    }
    std::cout << std::endl;
    try {
        throw VeryStupidUserEX("");
    } catch (ArcadeException &ex) {
        std::cout << "EXCEPTION " << ex.getName() << std::endl;
        std::cout << "WHAT : " << ex.what() << std::endl;
        std::cout << "WHERE: " << ex.where() << std::endl;
    }
    std::cout << std::endl;
    return (0);
}
