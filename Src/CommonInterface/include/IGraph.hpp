/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** IDisplay
*/

#ifndef ARCADE_IDISPLAY_HPP
#define ARCADE_IDISPLAY_HPP

#include <string>
#include "IEntity.hpp"

class IGraph {

    public:
        virtual ~IGraph() = default;
        virtual void drawCircle(float x, float y, float size, std::string color) = 0;
        virtual void drawRect(float x, float y, float size, std::string color) = 0;
        virtual void drawTriangle(float x, float y, float size, std::string color) = 0;
        virtual void drawText(const std::string &text) = 0;
        virtual void moveEntity(IEntity &entity) = 0;
        virtual void createWindow() = 0; // à voir avec l'autre groupe pour le return
        virtual void clearWindow() = 0;
        virtual void displayWindow() = 0;

    protected:

    private:

};


#endif//ARCADE_IDISPLAY_HPP
