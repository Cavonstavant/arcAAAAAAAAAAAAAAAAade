/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** IGame
*/

/// \file IGame.hpp

#ifndef ARCADE_IGAME_HPP
#define ARCADE_IGAME_HPP

#include "IDisplay.hpp"

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
    IGame() = default;

    virtual ~IGame() = default;

    /// \brief Initialize a game instance
    /// \param display a display instance to use
    /// \return true if the game was successfully initialized
    /// \note Each call to the method must be followed by a call to IGame::destroy()
    /// \warning Calling this method twice without calling IGame::destroy() beforehand will result in <b>undefined behavior</b>
    virtual bool setup(IDisplay &display) = 0;

    /// \brief Destroy a game instance
    /// \return true if the game was successfully destroyed
    /// \note Calling this method twice without calling IGame::setup() beforehand will result in <b>undefined behavior</b>
    virtual bool destroy() = 0;

    /// \brief Update the game's display
    /// \return true if the game was successfully updated
    /// \note Calling this method without calling IGame::setup() beforehand will result in <b>undefined behavior</b>
    virtual bool setDisplay(IDisplay &display) = 0;

    /// \brief Update the game's status
    /// \param state the new game's status
    /// \return true if the game was successfully updated
    /// \note Calling this method without calling IGame::setup() beforehand will result in <b>undefined behavior</b>
    virtual bool update(GameState state) = 0;

    /// \brief Get the game's status
    /// \return the game's status
    /// \note Calling this method without calling IGame::setup() beforehand will result in <b>undefined behavior</b>
    virtual GameState getState() const = 0;

    /// \brief starts the game
    /// \return true if the game was successfully started
    /// \note Calling this method without calling IGame::setup() beforehand will result in <b>undefined behavior</b>
    virtual bool start() = 0;
};


#endif//ARCADE_IGAME_HPP
