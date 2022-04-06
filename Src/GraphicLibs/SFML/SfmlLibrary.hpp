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

/// \brief SFML library
class SfmlLibrary : public IGraph {
    public:
        /// \brief Default Constructor
        SfmlLibrary();

        /// \brief Default destructor
        ~SfmlLibrary() = default;

        bool clearWindow() override;
        bool displayWindow() override;

        bool drawCircle(std::pair<int, int> pos, int radius,
                        Color color) override;
        bool drawRect(std::pair<int, int> pos, int width, int height,
                      Color color) override;
        bool drawText(std::pair<int, int> pos,
                      const std::string &content) override;
        bool drawEntity(IEntity &entity,
                        std::pair<int, int> pos) override;
        inline std::string getName() const override final { return _name;}

    private:
        /// \brief window member used to display every entities
        sf::RenderWindow _window;

        /// \brief Defines Width, Height, and BitsPerPixels of the window
        sf::VideoMode _videoMode;

        /// \brief Default font for every sf::Text in the SfmlLibrary
        sf::Font _font;

        /// \brief Graphic library name
        std::string _name;
};


#endif//ARCADE_SFMLLIBRARY_HPP
