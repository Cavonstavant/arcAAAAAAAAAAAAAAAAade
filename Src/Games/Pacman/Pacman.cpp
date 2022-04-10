/*
** EPITECH PROJECT, 2022
** Pacman.cpp.cc
** File description:
** Created by hjulien,
*/

#include "Pacman.hpp"
#include "../Common/AEntity.hpp"
#include "../Common/Object.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>

void Pacman::init(std::vector<std::shared_ptr<IEntity>> &entities)
{
    loadMap();
    _clock = std::chrono::high_resolution_clock::now();
    _iaClock = std::chrono::high_resolution_clock::now();
    _gameState = GameState::LOADED;
    _score = 0;
    _direction = Player::Direction::RIGHT;
    int cpt = 0;
    for (auto &i: _map) {
        for (int j = 0; j < MAP_WIDTH; j++)
            createEntity(i[j], entities, cpt, j);
        cpt++;
    }
}

void Pacman::createEntity(char symbol, std::vector<std::shared_ptr<IEntity>> &entities, int i, int j)
{
    const std::string texturePath = "Src/Games/Pacman/Resources/textures/pacman.png";
    const std::string enemyTexturePath = "Src/Games/Pacman/Resources/textures/enemy.png";

    if (symbol == 'W') {
        std::shared_ptr<Object> obj = std::make_shared<Object>(AEntity::ENTITY_TYPE::WALL);
        obj->setPos(std::pair<int, int>{i, j});
        entities.push_back(obj);
    } else if (symbol == 'G') {
        Enemy enemy1;
        Enemy enemy2;
        Enemy enemy3;

        enemy1.setTexturePath(std::filesystem::absolute(std::filesystem::path(enemyTexturePath).string()));
        enemy2.setTexturePath(std::filesystem::absolute(std::filesystem::path(enemyTexturePath).string()));
        enemy3.setTexturePath(std::filesystem::absolute(std::filesystem::path(enemyTexturePath).string()));
        _enemies[0] = std::make_shared<Enemy>(enemy1);
        _enemies[1] = std::make_shared<Enemy>(enemy2);
        _enemies[2] = std::make_shared<Enemy>(enemy3);
        _enemies[0]->setPos(std::pair<int, int>{i, j});
        _enemies[1]->setPos(std::pair<int, int>{i + 1, j});
        _enemies[2]->setPos(std::pair<int, int>{i + 2, j});
        entities.push_back(_enemies[0]);
        entities.push_back(_enemies[1]);
        entities.push_back(_enemies[2]);
    } else if (symbol == 'P') {
        Player pacman;
        pacman.setIsMoving(false);
        pacman.setBoosted(false);
        pacman.setTexturePath(std::filesystem::absolute(std::filesystem::path(texturePath)).string());
        _player = std::make_shared<Player>(pacman);
        _player->setPos(std::pair<int, int>{i, j});
        entities.push_back(_player);
    } else if (symbol == '.') {
        std::shared_ptr<Object> point = std::make_shared<Object>(AEntity::ENTITY_TYPE::POINT);
        point->setPos(std::pair<int, int>{i, j});
        entities.push_back(point);
    } else if (symbol == 'B') {
        std::shared_ptr<Object> point = std::make_shared<Object>(AEntity::ENTITY_TYPE::BONUS);
        point->setPos(std::pair<int, int>{i, j});
        entities.push_back(point);
    }
}

void Pacman::start()
{
    _gameState = GameState::RUNNING;
}

void Pacman::setPlayerDirection(Arcade::Evt event)
{
    if (moveDown(event) && !isThereAWallOnDirection(Player::DOWN))
        _player->setDirection(Player::DOWN);
    else if (moveUp(event) && !isThereAWallOnDirection(Player::UP))
        _player->setDirection(Player::UP);
    else if (moveLeft(event) && !isThereAWallOnDirection(Player::LEFT))
        _player->setDirection(Player::LEFT);
    else if (moveRight(event) && !isThereAWallOnDirection(Player::RIGHT))
        _player->setDirection(Player::RIGHT);
}

void Pacman::updateEnemyPos(int index)
{
    std::pair<int, int> pos;

    if (_enemies[index]->getDirection() == Player::Direction::UP) {
        pos.first = _enemies[index]->getPos().first - 1;
        pos.second = _enemies[index]->getPos().second;
        _enemies[index]->setPos(pos);
    } else if (_enemies[index]->getDirection() == Player::Direction::DOWN) {
        pos.first = _enemies[index]->getPos().first + 1;
        pos.second = _enemies[index]->getPos().second;
        _enemies[index]->setPos(pos);
    } else if (_enemies[index]->getDirection() == Player::Direction::LEFT) {
        pos.first = _enemies[index]->getPos().first;
        pos.second = _enemies[index]->getPos().second - 1;
        _enemies[index]->setPos(pos);
    } else if (_enemies[index]->getDirection() == Player::Direction::RIGHT) {
        pos.first = _enemies[index]->getPos().first;
        pos.second = _enemies[index]->getPos().second + 1;
        _enemies[index]->setPos(pos);
    }
}

void Pacman::update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 3);

    if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - _iaClock).count() > 0 && !(_enemies[0]->getIsMoving())) {
        _enemies[0]->setIsMoving(true);
        _enemies[1]->setIsMoving(true);
        _enemies[2]->setIsMoving(true);
        _iaClock = std::chrono::high_resolution_clock::now();
    }
    if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _iaClock).count() > 500 && _enemies[0]->getIsMoving()) {
        for (int i = 0; i < 3; i++) {
            if (nextToTheWall(_enemies[i]->getDirection(), i))
                _enemies[i]->setDirection(static_cast<AEntity::Direction>(dist4(rng)));
            if (!nextToTheWall(_enemies[i]->getDirection(), i))
                updateEnemyPos(i);
        }
        _iaClock = std::chrono::high_resolution_clock::now();
    }
    while (!events.empty()) {
        setPlayerDirection(events.top());
        events.pop();
    }
    if (!isThereAWallOnDirection(_player->getDirection()) && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _clock).count() > 500) {
        updatePlayerPos();
        _clock = std::chrono::high_resolution_clock::now();
    }
    for (auto i = entities.begin(); i != entities.end(); i++) {
        if (i->get()->getPos() == _player->getPos() && (i->get()->getType() == IEntity::POINT || i->get()->getType() == IEntity::BONUS)) {
            entities.erase(i);
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
    if (input.evt_type == Arcade::Evt::KEY && (input.key.key == 'z' || input.key.key == 'Z'))
        return true;
    return false;
}

bool Pacman::moveDown(Arcade::Evt input)
{
    if (input.evt_type == Arcade::Evt::KEY && (input.key.key == 's' || input.key.key == 'S'))
        return true;
    return false;
}

bool Pacman::moveRight(Arcade::Evt input)
{
    if (input.evt_type == Arcade::Evt::KEY && (input.key.key == 'd' || input.key.key == 'D'))
        return true;
    return false;
}

bool Pacman::moveLeft(Arcade::Evt input)
{
    if (input.evt_type == Arcade::Evt::KEY && (input.key.key == 'q' || input.key.key == 'Q'))
        return true;
    return false;
}

void Pacman::close(std::vector<std::shared_ptr<IEntity>> &entities)
{
    entities.clear();
}

bool Pacman::isThereAWallOnDirection(Player::Direction direction)
{
    if (direction == Player::UP && _map[_player->getPos().first - 1][_player->getPos().second] == 'W')
        return true;
    if (direction == Player::DOWN && _map[_player->getPos().first + 1][_player->getPos().second] == 'W')
        return true;
    if (direction == Player::LEFT && _map[_player->getPos().first][_player->getPos().second - 1] == 'W')
        return true;
    if (direction == Player::RIGHT && _map[_player->getPos().first][_player->getPos().second + 1] == 'W')
        return true;
    return false;
}

void Pacman::updatePlayerPos()
{
    std::pair<int, int> pos;

    if (_player->getDirection() == Player::Direction::UP) {
        pos.first = _player->getPos().first - 1;
        pos.second = _player->getPos().second;
        _player->setPos(pos);
    } else if (_player->getDirection() == Player::Direction::DOWN) {
        pos.first = _player->getPos().first + 1;
        pos.second = _player->getPos().second;
        _player->setPos(pos);
    } else if (_player->getDirection() == Player::Direction::LEFT) {
        pos.first = _player->getPos().first;
        pos.second = _player->getPos().second - 1;
        _player->setPos(pos);
    } else if (_player->getDirection() == Player::Direction::RIGHT) {
        pos.first = _player->getPos().first;
        pos.second = _player->getPos().second + 1;
        _player->setPos(pos);
    }
}

void Pacman::loadMap()
{
    std::string line;
    std::ifstream file("Src/Games/Pacman/Resources/map");

    if (file.is_open()) {
        for (auto &i: _map) {
            getline(file, line);
            std::cout << line << std::endl;
            i = line;
        }
    }
    file.close();
}

void Pacman::setState(IGame::GameState state)
{
    _gameState = state;
}

bool Pacman::nextToTheWall(Player::Direction direction, int index)
{
    if (direction == Player::UP && _map[_enemies[index]->getPos().first - 1][_enemies[index]->getPos().second] == 'W')
        return true;
    if (direction == Player::DOWN && _map[_enemies[index]->getPos().first + 1][_enemies[index]->getPos().second] == 'W')
        return true;
    if (direction == Player::LEFT && _map[_enemies[index]->getPos().first][_enemies[index]->getPos().second - 1] == 'W')
        return true;
    if (direction == Player::RIGHT && _map[_enemies[index]->getPos().first][_enemies[index]->getPos().second + 1] == 'W')
        return true;
    return false;
}
