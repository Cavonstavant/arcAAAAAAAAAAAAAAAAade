/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** MainMenu
*/

#pragma once

#include "../LibManager.hpp"
#include "Button.hpp"
#include "IGame.hpp"
#include <vector>

/// \file Src/Core/MainMenu/MainMenu.hpp
/// \brief MainMenu class
class MainMenu : public IGame {
    public:
        /// \brief Constructor
        MainMenu();
        /// \brief Destructor
        ~MainMenu() override;

        /// \brief Initialize the menu & initialize
        /// \param std::vector<std::shared_ptr<IEntity>> &entities Vector of current entities
        void init(std::vector<std::shared_ptr<IEntity>> &entities) override;
        /// \brief Close the menu & clear vector of entities
        /// \param std::vector<std::shared_ptr<IEntity>> &entities Vector of current entities
        void close(std::vector<std::shared_ptr<IEntity>> &entities) override;

        /// \brief Update the game's entities
        /// \param entities The entity vector of the game
        /// \param events The event stack of the game
        void update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events) override;
        /// \brief Get the game's status
        /// \return the game's status
        [[nodiscard]] GameState getState() const override
        {
            return _gameState;
        }
        /// \brief Setter to _gameState member
        void setState(GameState state) override
        {
            _gameState = state;
        }

        /// \brief starts the game
        void start() override;
        /// \brief Get the menu's name
        [[nodiscard]] std::string getLibraryName() const final;
        /// \brief Getter used to know if the game is over
        /// \return boolean
        bool getIsGameOver() override;
        /// \brief Getter used to get the score of the player in the game
        /// \return The score as an Integer
        int getScore() const override;

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
