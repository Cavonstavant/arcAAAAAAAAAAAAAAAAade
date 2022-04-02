/*
** EPITECH PROJECT, 2022
** SfmlLibrary.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_SFMLLIBRARY_HPP
#define ARCADE_SFMLLIBRARY_HPP

#include "../../CommonInterface/include/IGraph.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/// \brief SFML library using float as template value from IGraph
class SfmlLibrary : public IGraph<float> {
public:
    /// \brief Default Constructor
    SfmlLibrary();

    /// \brief Default destructor
    ~SfmlLibrary() = default;

    bool clearWindow() override;
    bool displayWindow() override;

    bool drawCircle(std::pair<float, float> pos, float radius,
                    Color color) override;
    bool drawRect(std::pair<float, float> pos, float width, float height,
                  Color color) override;
    bool drawText(std::pair<float, float> pos,
                  const std::string &content) override;
    bool drawEntity(IEntity &entity,
                    std::pair<float, float> pos) override;

private:
    /// \brief window member using to display every entities
    sf::RenderWindow _window;

    /// \brief Defines Width, Height, and BitsPerPixels of the window
    sf::VideoMode _videoMode;

    /// \brief Default font for every sf::Text in the SfmlLibrary
    sf::Font _font;
};


#endif//ARCADE_SFMLLIBRARY_HPP
