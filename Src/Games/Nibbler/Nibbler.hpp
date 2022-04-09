/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Nibbler
*/

#pragma once

#include "../Common/Object.hpp"
#include "../Common/Player.hpp"
#include "../Common/Score.hpp"
#include "IGame.hpp"
#include <chrono>
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
        /// \brief Closes the library
        void close(std::vector<std::shared_ptr<IEntity>> &entities) override;
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
        std::list<std::shared_ptr<Player>> _snake;
        /// \brief The game clock
        std::chrono::high_resolution_clock::time_point _clock;
        /// \brief The fruit
        std::shared_ptr<Object> _fruit;
        /// \brief The last tail's last direction
        IEntity::Direction _lastTailDir;
        /// \brief The last tails's last position
        std::pair<int, int> _lastTailPos;
        /// \brief The game's speed multiplier
        float _speed;
        /// \brief The game's score
        std::shared_ptr<Score> _score;

        /// \brief Get the elapsed time since the last update in milliseconds
        /// \return the elapsed time since the last update in milliseconds
        int getClockTimeMS();
        /// \brief Restarts the clock
        void resetClock();
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
        /// \brief Move the snake
        void moveSnake();
        /// \brief Check if the snake is on a fruit
        /// \param entities The entity vector of the game
        /// \return true if the snake is on a fruit, false otherwise
        bool snakeIsOnAFruit(std::vector<std::shared_ptr<IEntity>> &entities);
        /// \brief Go to the next level
        void nextLevel(std::vector<std::shared_ptr<IEntity>> &entities);
        /// \brief Init entities
        /// \param entities The entity vector of the game
        void initEntities(std::vector<std::shared_ptr<IEntity>> &entities);
        /// \brief Create new head
        /// \param entities The entity vector of the game
        Player createNewHead(int x, int y);
        /// \brief Create new tail
        /// \param entities The entity vector of the game
        Player createNewTail(int x, int y);
        /// \brief Create new fruit
        /// \param entities The entity vector of the game
        Object createNewFruit(int x, int y);
        /// \brief Check if the snake is on itself
        /// \return true if the snake is on itself, false otherwise
        bool snakeIsOnItself();
};
