/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** MainMenu
*/

#pragma once

#include "../../Games/Common/Button.hpp"
#include "IGame.hpp"
#include "IGraph.hpp"

class MainMenu : public IGame {
    public:
        /// \brief Constructor
        MainMenu(std::vector<std::shared_ptr<IEntity>> &entities);
        /// \brief Destructor
        ~MainMenu();

        /// \brief Update the game's entities
        /// \param entities The entity vector of the game
        /// \param events The event stack of the game
        void update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events) override;
        /// \brief Get the game's status
        /// \return the game's status
        GameState getState() const;
        /// \brief starts the game
        void start();

    protected:
    private:
        std::vector<std::shared_ptr<Button>> _buttons;
        GameState _gameState;

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
};
