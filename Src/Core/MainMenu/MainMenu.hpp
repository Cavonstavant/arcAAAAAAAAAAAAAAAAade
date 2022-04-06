/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** MainMenu
*/

#pragma once

#include "../../Games/Common/Button.hpp"
#include "IGame.hpp"
#include <vector>

/// \file MainMenu.hpp
/// \brief MainMenu class
class MainMenu : public IGame {
    public:
        /// \brief Constructor
        MainMenu();
        /// \brief Destructor
        ~MainMenu();

        /// \brief Initialize the menu
        void init(std::vector<std::shared_ptr<IEntity>> &entities) override;

        /// \brief Update the game's entities
        /// \param entities The entity vector of the game
        /// \param events The event stack of the game
        void update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events) override;
        /// \brief Get the game's status
        /// \return the game's status
        GameState getState() const;
        /// \brief starts the game
        void start();
        /// \brief get the library name
        /// \return the library name
        std::string getLibraryName() const;

    protected:
    private:
        /// \brief Vector of all the buttons
        std::vector<std::shared_ptr<Button>> _buttons;
        /// \brief The game's state
        GameState _gameState;
        /// \brief Vector of the graphical libraries
        std::vector<std::string> _graphicalLibraries;
        /// \brief Vector of the game libraries
        std::vector<std::string> _gameLibraries;

        /// \brief Manage the events
        /// \param events The event stack of the game
        /// \param entities The entity vector of the game
        void manageEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities);
        /// \brief Manage the click events
        /// \param event The event stack of the game
        /// \param entities The entity vector of the game
        void manageClickEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities);
        /// \brief Manage the key events
        /// \param event The event stack of the game
        /// \param entities The entity vector of the game
        void manageKeyEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities);
        /// \brief Gets all the libraries and fills the vectors
        void getAllLibraries();
};
