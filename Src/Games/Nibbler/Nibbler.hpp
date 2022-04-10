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

/// \file Src/Games/Nibbler/Nibbler.hpp
/// \brief Nibbler class
class Nibbler : public IGame {
public:
    /// \brief Constructor
    Nibbler();
    /// \brief Destructor
    ~Nibbler();

    /// \brief Initialize the game
    /// \param std::vector<std::shared_ptr<IEntity>> &entities vector of current entities
    void init(std::vector<std::shared_ptr<IEntity>> &entities) override;
    /// \brief Closes the library
    /// \param std::vector<std::shared_ptr<IEntity>> &entities vector of current entities
    void close(std::vector<std::shared_ptr<IEntity>> &entities) override;
    /// \brief Update the game's entities
    /// \param entities The entity vector of the game
    /// \param events The event stack of the game
    void update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events) override;
    /// \brief Get the game's status
    /// \return the game's status
    GameState getState() const;
    /// \brief Set the game's state
    /// \param state The game's state
    void setState(GameState state);
    /// \brief Get the game's score
    /// \return the game's score
    std::shared_ptr<IEntity> getScore();
    /// \brief starts the game
    void start();
    /// \brief get the library name
    /// \return the library name
    std::string getLibraryName() const;
    /// \brief Get the game's score
    /// \return the game's score
    int getScore() const override;
    /// \brief Get if the game is over
    /// \return if the game is over
    bool getIsGameOver() override;


protected:
private:
    /// \brief The snake's direction on its last movement
    IEntity::Direction _lastDir;
    /// \brief The game's state
    GameState _gameState;
    /// \brief The snake (list of all its parts)
    std::list<std::shared_ptr<Player>> _snake;
    /// \brief The walls
    std::list<std::shared_ptr<Object>> _walls;
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
    int _score;

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
    /// \warning Not implemented at the moment
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
    /// \return the created head
    Player createNewHead(int x, int y);
    /// \brief Create new tail
    /// \param entities The entity vector of the game
    /// \return the created tail
    Player createNewTail(int x, int y);
    /// \brief Create new fruit
    /// \param entities The entity vector of the game
    /// \return the created fruit
    Object createNewFruit(int x, int y);
    /// \brief Create new wall
    /// \param entities The entity vector of the game
    /// \return the created wall
    Object createNewWall(int x, int y);
    /// \brief Check if the snake hits itself or a wall
    /// \return true if the snake hits itself or a wall, false otherwise
    bool snakeIsDeadCollision();
    /// \brief Get the next position of the snake's head
    /// \return the next position of the snake's head
    std::pair<int, int> getNextPos(std::pair<int, int> pos, IEntity::Direction dir);
};
