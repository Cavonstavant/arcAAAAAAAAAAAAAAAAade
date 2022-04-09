/*
** EPITECH PROJECT, 2022
** Pacman.cpp.cc
** File description:
** Created by hjulien,
*/

#include "Pacman.hpp"
#include "../Common/Object.hpp"
#include "../Common/AEntity.hpp"
#include "../Common/Enemy.hpp"
#include <fstream>

void Pacman::init(std::vector<std::shared_ptr<IEntity>> &entities)
{
    loadMap();
    _clock = std::chrono::high_resolution_clock::now();
    _gameState = GameState::LOADED;
    _score = 0;
    _direction = Player::Direction::RIGHT;
    for (auto & i : _map) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            entities.push_back(createEntity(i[j]));
        }
    }
}

std::shared_ptr<IEntity> Pacman::createEntity(char symbol)
{
    if (symbol == 'W')
        return std::make_shared<Object>(AEntity::ENTITY_TYPE::WALL);
    else if (symbol == 'G')
        return std::shared_ptr<Enemy>();
    else if (symbol == 'P') {
        Player pacman;
        pacman.setIsMoving(false);
        pacman.setBoosted(false);
        pacman.setTexturePath("Resources/textures/pacman.png");
        _player = std::make_shared<Player>(pacman);
        return _player;
    }
    else if (symbol == '.')
        return std::make_shared<Object>(AEntity::ENTITY_TYPE::POINT);
    return nullptr;
}

void Pacman::start()
{
    _gameState = GameState::RUNNING;
}

void Pacman::setPlayerDirection(Arcade::Evt event)
{
    if (moveDown(event))
        _player->setDirection(Player::DOWN);
    else if (moveUp(event))
        _player->setDirection(Player::UP);
    else if (moveLeft(event))
        _player->setDirection(Player::LEFT);
    else if (moveRight(event))
        _player->setDirection(Player::RIGHT);
}

void Pacman::updatePlayerPos()
{
    std::pair<int, int> pos;

    if (_player->getDirection() == Player::Direction::UP) {
        pos.first = _player->getPos().first;
        pos.second = _player->getPos().second - 1;
        _player->setPos(pos);
    } else if (_player->getDirection() == Player::Direction::DOWN) {
        pos.first = _player->getPos().first;
        pos.second = _player->getPos().second + 1;
        _player->setPos(pos);
    } else if (_player->getDirection() == Player::Direction::LEFT) {
        pos.first = _player->getPos().first - 1;
        pos.second = _player->getPos().second;
        _player->setPos(pos);
    } else if (_player->getDirection() == Player::Direction::RIGHT) {
        pos.first = _player->getPos().first + 1;
        pos.second = _player->getPos().second;
        _player->setPos(pos);
    }
}

void Pacman::update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events)
{
    while (!events.empty()) {
        setPlayerDirection(events.top());
        events.pop();
        if (!isThereAWallOnDirection(_player->getDirection())
        && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _clock).count() > 500) {
            updatePlayerPos();
            _clock = std::chrono::high_resolution_clock::now();
        }
    }
    for (const auto& i : entities) {
        if (i->getPos() == _player->getPos() && i->getType() == IEntity::POINT) {
            _score += 100;
        }
    }
}

std::string Pacman::getLibraryName() const
{
    return "Pacman";
}

IGame::GameState Pacman::getState() const
{
    return _gameState;
}

bool Pacman::moveUp(Arcade::Evt input)
{
    if (input.evt_type == Arcade::Evt::KEY
        && (input.key.key == 'z'
            || input.key.key == 'Z'))
        return true;
    return false;
}

bool Pacman::moveDown(Arcade::Evt input)
{
    if (input.evt_type == Arcade::Evt::KEY
        && (input.key.key == 's'
            || input.key.key == 'S'))
        return true;
    return false;
}

bool Pacman::moveRight(Arcade::Evt input)
{
    if (input.evt_type == Arcade::Evt::KEY
        && (input.key.key == 'd'
            || input.key.key == 'D'))
        return true;
    return false;
}

bool Pacman::moveLeft(Arcade::Evt input)
{
    if (input.evt_type == Arcade::Evt::KEY
        && (input.key.key == 'q'
            || input.key.key == 'Q'))
        return true;
    return false;
}

void Pacman::close(std::vector<std::shared_ptr<IEntity>> &entities)
{
    entities.clear();
}

bool Pacman::isThereAWallOnDirection(Player::Direction direction)
{
    if (direction == Player::UP && _map[_player->getPos().second - 1][_player->getPos().first] == 'W')
        return true;
    if (direction == Player::DOWN && _map[_player->getPos().second + 1][_player->getPos().first] == 'W')
        return true;
    if (direction == Player::LEFT && _map[_player->getPos().second][_player->getPos().first - 1] == 'W')
        return true;
    if (direction == Player::RIGHT && _map[_player->getPos().second][_player->getPos().first + 1] == 'W')
        return true;
    return false;
}

void Pacman::loadMap()
{
    std::string line;
    std::ifstream file("Resources/map");

    if (file.is_open()) {
        for (auto & i : _map) {
            getline(file, line);
            i = line;
        }
    }
    file.close();
}
