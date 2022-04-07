/*
** EPITECH PROJECT, 2022
** Pacman.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_PACMAN_HPP
#define ARCADE_PACMAN_HPP

#include "IGame.hpp"
#include "Event.hpp"
#include "../Common/Player.hpp"

class Pacman : public IGame {
    public:
        /// \brief Default constructor
        Pacman();
        ///\brief Default Destructor
        ~Pacman() override = default;

        std::string getName() const override;
        void update(std::vector<std::shared_ptr<IEntity>> &entities,
                    std::stack<Arcade::Evt> &events) override;
        GameState getState() const override;
        void start() override;

    private:
        Player _player;
        bool _eating;
        clock_t clock;
        unsigned int _score;
        Arcade::Evt _currentInput;
        Arcade::Evt _direction;
        bool moveUp(Arcade::Evt input);
        bool moveDown(Arcade::Evt input);
        bool moveRight(Arcade::Evt input);
        bool moveLeft(Arcade::Evt input);
        GameState _gameState;

};


#endif //ARCADE_PACMAN_HPP
