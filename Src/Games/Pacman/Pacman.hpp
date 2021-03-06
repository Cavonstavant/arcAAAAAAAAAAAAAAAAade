/*
** EPITECH PROJECT, 2022
** Pacman.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_PACMAN_HPP
#define ARCADE_PACMAN_HPP

#include "../Common/Enemy.hpp"
#include "../Common/Player.hpp"
#include "Event.hpp"
#include "IGame.hpp"
#include <chrono>

#define MAP_HEIGHT 21
#define MAP_WIDTH 32

/// \file Src/Games/Pacman/Pacman.hpp
/// \brief Pacman Class inherits from IGame
class Pacman : public IGame {
    public:
        /// \brief Default constructor
        /// \warning You must call function init after calling the constructor to initialize all the entities
        /// Otherwise it will be impossible to play
        Pacman() = default;
        /// \brief Default Destructor
        ~Pacman() override = default;

        /// \brief Initializing the whole game :
        /// Load the _map
        /// Creating every entities needed to run the game
        /// Initialize the clock
        /// \param Empty vector of entity, filling it after load the map
        /// \warning Must be the first function called to use the game, otherwise no entities will be created
        void init(std::vector<std::shared_ptr<IEntity>> &entities) override;

        /// \brief Used to know the current game you are playing
        /// \return std::string with the name of the current gameLibrary
        [[nodiscard]] std::string getLibraryName() const override;

        /// \brief This function is used to update every entities according to the incoming stack of events
        void update(std::vector<std::shared_ptr<IEntity>> &entities,
                    std::stack<Arcade::Evt> &events) override;

        /// \brief used to know the state of the game
        [[nodiscard]] GameState getState() const override;
        void setState(GameState state) override;

        /// \brief Just turn the gameState to RUNNING
        void start() override;

        /// \brief Stop the game, destroy every Entities
        /// \param Vector of every entities of the game
        void close(std::vector<std::shared_ptr<IEntity>> &entities) override;

    private:
        /// \brief IEntity Player representing the pacman Player
        std::shared_ptr<Player> _player;

        /// \brief Array of shared pointer enemies representing ghosts in pacman
        std::shared_ptr<Enemy> _enemies[3];

        /// \brief _map is represented by the map in Resources, we load it here to use it easier
        std::string _map[MAP_HEIGHT];

        /// \brief simple clock to anime and move entities
        std::chrono::high_resolution_clock::time_point _clock;

        /// \brief simple IAClock to anime and move Enemies Entities
        std::chrono::high_resolution_clock::time_point _iaClock;

        /// \brief Simple bonusClock to know the
        std::chrono::high_resolution_clock::time_point _bonusClock;

        /// \brief represents the number of points on the map
        int _points;

        /// \brief The score of the game the player is currently playing
        int _score{};

        /// \brief Boolean to know if the player lose or not
        bool _isGameOver;

        /// \brief The actual direction of the player
        Enemy::Direction _direction;

        /// \brief Represents as enum GameState the actual gameState
        GameState _gameState;

        /// \brief Used to load the map of pacman in the member std::string _map[]
        void loadMap();

        /// \brief Used to update the player position according to his direction
        void updatePlayerPos();

        /// \brief Used to set the direction of the player according to the input send as parameter
        /// \param Arcade::Evt input is the last input used to change (or not) the direction of the player
        void setPlayerDirection(Arcade::Evt input);

        /// \brief Used to know if the _player can move to the top
        /// \param Arcade::Evt input represents the last input
        static bool moveUp(Arcade::Evt input);

        /// \brief Used to know if the _player can move to the bottom
        /// \param Arcade::Evt input represents the last input
        static bool moveDown(Arcade::Evt input);

        /// \brief Used to know if the _player can move to the right
        /// \param Arcade::Evt input represents the last input
        static bool moveRight(Arcade::Evt input);

        /// \brief Used to know if the _player can move to the left
        /// \param Arcade::Evt input represents the last input
        static bool moveLeft(Arcade::Evt input);

        /// \brief Used to know if the _player is able to go on the direction passed as parameter
        /// \return False if there is no wall
        /// \param Player::Direction direction to know where the _player want to move
        bool isThereAWallOnDirection(Player::Direction direction);

        /// \brief Used at the initialization to create all the entities
        /// \param Char symbol represents one char of the _map, as a symbol, it represents an Entity type
        /// \return std::shared_ptr<IEntity>> represents the different type of Entity just created
        void createEntity(char symbol, std::vector<std::shared_ptr<IEntity>> &entities, int i, int j);

        /// \brief Used to update the Enemy position according to his direction
        /// \param The index from 0 to 3 of the enemy to update
        void updateEnemyPos(int index);

        /// \brief Used to know if the enemy is next to a wall according to the direction as parameter
        /// \param Player::Direction direction to know where the enemy want to move
        /// \param Index of the enemy from 0 to 3
        /// \return False if there is no wall
        bool nextToTheWall(Player::Direction direction, int index);

        /// \brief Setter for _isGameOver
        /// \param isGameOver boolean
        void setIsGameOver(bool isGameOver);

        /// \brief Getter for _isGameOver
        /// \return Boolean _isGameOver
        bool getIsGameOver() override;

        /// \brief Getter for the score inGame
        [[nodiscard]] int getScore() const override;
};

#endif//ARCADE_PACMAN_HPP
