/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Nibbler
*/

#pragma once

#include "../../Games/Common/Button.hpp"
#include "../../Games/Common/Player.hpp"
#include "IGame.hpp"
#include <list>
#include <vector>

/// \file Nibbler.hpp
/// \brief Nibbler class
class Nibbler : public IGame {
    public:
        /// \brief Constructor
        Nibbler();
        /// \brief Destructor
        ~Nibbler();

        /// \brief Initialize the game
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
        /// \brief The game's state
        GameState _gameState;
        /// \brief The snake (list of all its parts)
        std::list<Player> _snake;

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
