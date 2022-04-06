/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** IGame
*/

/// \file IGame.hpp

#ifndef ARCADE_IGAME_HPP
#define ARCADE_IGAME_HPP

#include "Event.hpp"
#include "Grid.hpp"
#include "IEntity.hpp"
#include <memory>
#include <stack>
#include <vector>

/// Game instance
class IGame {
    public:
        /// Represents the game's status
        enum class GameState {
            /// Represents the game at it's initial state
            LOADED,
            /// Represents the game when running
            RUNNING,
            /// Represents the previously running game is paused
            PAUSED,
            /// Represents the game over
            STOPPED,
        };

        virtual ~IGame() = default;

        /// \brief Update the game's status
        /// \param entities The entity vector of the game
        /// \param events The event stack of the game
        virtual void update(std::vector<std::shared_ptr<IEntity>> &entities,
                            std::stack<Arcade::Evt> &events) = 0;

        /// \brief Get the game's status
        /// \return the game's status
        virtual GameState getState() const = 0;

        /// \brief Get the game's name
        virtual std::string getLibraryName() const = 0;

        /// \brief starts the game
        virtual void start() = 0;
};

#endif// ARCADE_IGAME_HPP
