/*
** EPITECH PROJECT, 2022
** SfmlLibrary.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_SFMLLIBRARY_HPP
#define ARCADE_SFMLLIBRARY_HPP

#include "IGraph.hpp"
#include "Event.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/// \brief SFML library
class SfmlLibrary : public IGraph {
    public:
        /// \brief Default Constructor
        /// Creating & Initializing the window
        /// Loading the member _font for Resources. ARCADE_N.TTF as default font
        SfmlLibrary();

        /// \brief Default destructor
        /// Closing window previously opened in constructor
        ~SfmlLibrary();

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
        Arcade::Evt getInput() const override;
        std::string getLibraryName() const override;


    private:
        /// \brief window member used to display every entities
        sf::RenderWindow _window;

        /// \brief Defines Width, Height, and BitsPerPixels of the window
        sf::VideoMode _videoMode;

        /// \brief Default font for every sf::Text in the SfmlLibrary
        sf::Font _font;
};


#endif//ARCADE_SFMLLIBRARY_HPP
