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
    entities.clear();
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
        enemy1.setTermTexture('G', Color::TermColors::RED, Color::TermColors::BLACK);
        enemy2.setTexturePath(std::filesystem::absolute(std::filesystem::path(enemyTexturePath).string()));
        enemy2.setTermTexture('G', Color::TermColors::RED, Color::TermColors::BLACK);
        enemy3.setTexturePath(std::filesystem::absolute(std::filesystem::path(enemyTexturePath).string()));
        enemy3.setTermTexture('G', Color::TermColors::RED, Color::TermColors::BLACK);
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
        pacman.setTermTexture('<', Color::TermColors::GREEN, Color::TermColors::BLACK);
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
    if (_enemies[index]->getPos().first == 9 && _enemies[index]->getPos().second >= 30)
        _enemies[index]->setPos(std::pair<int, int>{9, 0});
    else if (_enemies[index]->getPos().first == 9 && _enemies[index]->getPos().second <= 0)
        _enemies[index]->setPos(std::pair<int, int>{9, 30});
}

void Pacman::update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 3);
    const std::string sickEnemyTexturePath = "Src/Games/Pacman/Resources/textures/enemySick.png";
    const std::string EnemyTexturePath = "Src/Games/Pacman/Resources/textures/enemy.png";
    bool victory = true;

    if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - _bonusClock).count() > 10) {
        _enemies[0]->setEnrage(true);
        _enemies[0]->setTexturePath(std::filesystem::absolute(std::filesystem::path(EnemyTexturePath).string()));
        _enemies[0]->setTermTexture('G', Color::TermColors::BLUE, Color::TermColors::BLACK);
        _enemies[1]->setEnrage(true);
        _enemies[1]->setTexturePath(std::filesystem::absolute(std::filesystem::path(EnemyTexturePath).string()));
        _enemies[1]->setTermTexture('G', Color::TermColors::BLUE, Color::TermColors::BLACK);
        _enemies[2]->setEnrage(true);
        _enemies[2]->setTexturePath(std::filesystem::absolute(std::filesystem::path(EnemyTexturePath).string()));
        _enemies[2]->setTermTexture('G', Color::TermColors::BLUE, Color::TermColors::BLACK);
        _bonusClock = std::chrono::high_resolution_clock::now();
    }
    if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - _iaClock).count() > 10 && !(_enemies[0]->getIsMoving())) {
        _enemies[0]->setIsMoving(true);
        _enemies[1]->setIsMoving(true);
        _enemies[2]->setIsMoving(true);
        _iaClock = std::chrono::high_resolution_clock::now();
    }
    if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _iaClock).count() > 400 && _enemies[0]->getIsMoving() && _enemies[0]->getEnrage()) {
        for (int i = 0; i < 3; i++) {
            if (nextToTheWall(_enemies[i]->getDirection(), i))
                _enemies[i]->setDirection(static_cast<AEntity::Direction>(dist4(rng)));
            if (!nextToTheWall(_enemies[i]->getDirection(), i))
                updateEnemyPos(i);
        }
        _iaClock = std::chrono::high_resolution_clock::now();
    }
    if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _iaClock).count() > 900 && _enemies[0]->getIsMoving() && !_enemies[0]->getEnrage()) {
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
    if (!isThereAWallOnDirection(_player->getDirection()) && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _clock).count() > 400) {
        updatePlayerPos();
        _clock = std::chrono::high_resolution_clock::now();
    }
    for (auto i = entities.begin(); i != entities.end(); i++) {
        if (i->get()->getPos() == _player->getPos() && (i->get()->getType() == IEntity::POINT)) {
            entities.erase(i);
            _score += 1;
            victory = false;
        }
        if (i->get()->getPos() == _player->getPos() && i->get()->getType() == IEntity::BONUS) {
            _enemies[0]->setEnrage(false);
            _enemies[0]->setTexturePath(std::filesystem::absolute(std::filesystem::path(sickEnemyTexturePath).string()));
            _enemies[0]->setTermTexture('g', Color::TermColors::BLUE, Color::TermColors::BLACK);
            _enemies[1]->setEnrage(false);
            _enemies[1]->setTexturePath(std::filesystem::absolute(std::filesystem::path(sickEnemyTexturePath).string()));
            _enemies[1]->setTermTexture('g', Color::TermColors::BLUE, Color::TermColors::BLACK);
            _enemies[2]->setEnrage(false);
            _enemies[2]->setTexturePath(std::filesystem::absolute(std::filesystem::path(sickEnemyTexturePath).string()));
            _enemies[2]->setTermTexture('g', Color::TermColors::BLUE, Color::TermColors::BLACK);
            _bonusClock = std::chrono::high_resolution_clock::now();
            entities.erase(i);
            victory = false;
        }
        if (dynamic_cast<Enemy *>(i->get()))
            if (i->get()->getPos() == _player->getPos() && i->get()->getType() == IEntity::ENEMY) {
                if (!dynamic_cast<Enemy *>(i->get())->getEnrage()) {
                    _score += 2;
                    i->get()->setPos(std::pair<int, int>{9, 16});
                } else {
                    _isGameOver = true;
                    return;
                }
            }
    }
    if (victory)
        init(entities);
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
    if (_player->getPos().first == 9 && _player->getPos().second >= 30)
        _player->setPos(std::pair<int, int>{9, 0});
    else if (_player->getPos().first == 9 && _player->getPos().second <= 0)
        _player->setPos(std::pair<int, int>{9, 30});
}

void Pacman::loadMap()
{
    std::string line;
    std::ifstream file("Src/Games/Pacman/Resources/map");

    if (file.is_open()) {
        for (auto &i: _map) {
            getline(file, line);
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

void Pacman::setIsGameOver(bool isGameOver)
{
    _gameState = IGame::GameState::STOPPED;
    _isGameOver = isGameOver;
}

bool Pacman::getIsGameOver()
{
    return _isGameOver;
}

int Pacman::getScore() const
{
    return _score;
}
