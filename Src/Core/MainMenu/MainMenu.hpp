/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** MainMenu
*/

#pragma once

#include "Button.hpp"
#include "IGame.hpp"
#include "../LibManager.hpp"
#include <vector>

/// \file MainMenu.hpp
/// \brief MainMenu class
class MainMenu : public IGame {
    public:
        /// \brief Constructor
        MainMenu();
        /// \brief Destructor
        ~MainMenu() override;

        /// \brief Initialize the menu
        void init(std::vector<std::shared_ptr<IEntity>> &entities) override;
        /// \brief Close the menu
        void close(std::vector<std::shared_ptr<IEntity>> &entities) override;

        /// \brief Update the game's entities
        /// \param entities The entity vector of the game
        /// \param events The event stack of the game
        void update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events) override;
        /// \brief Get the game's status
        /// \return the game's status
        [[nodiscard]] GameState getState() const override { return _gameState; }

        void setState(GameState state) override { _gameState = state; }

        /// \brief starts the game
        void start() override;
        /// \brief Get the menu's name
        [[nodiscard]] std::string getLibraryName() const final;

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
