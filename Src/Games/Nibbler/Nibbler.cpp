/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "Event.hpp"
#include <ctime>
#include <filesystem>
#include <random>
#include <stack>
#include <iostream>

Nibbler::Nibbler() : _gameState(IGame::GameState::STOPPED), _lastTailDir(IEntity::Direction::RIGHT) ,_lastTailPos(std::make_pair(0, 0)), _score(0)
    {}

Nibbler::~Nibbler() = default;


void Nibbler::init(std::vector<std::shared_ptr<IEntity>> &entities)
{
    srand((unsigned) time(NULL));
    _gameState = GameState::LOADED;
    _lastDir = IEntity::Direction::RIGHT;
    _lastTailDir = IEntity::Direction::RIGHT;
    _lastTailPos = std::make_pair(0, 0);
    _speed = 1;
    Object fruit = createNewFruit(rand() % (GRID_WIDTH - (GRID_WIDTH / 4)), rand() % (GRID_HEIGHT));
    fruit.setPos(std::make_pair((rand() % ((GRID_WIDTH - (GRID_WIDTH / 4)) - 2)) + 1, (rand() % ((GRID_HEIGHT) - 2)) + 1));
    fruit.setTermTexture('*', Color::TermColors::YELLOW, Color::TermColors::BLACK);
    _fruit = std::make_shared<Object>(fruit);

    initEntities(entities);
}

void Nibbler::close(std::vector<std::shared_ptr<IEntity>> &entities)
{
    _gameState = GameState::STOPPED;
    _snake.clear();
    entities.clear();
}

Player Nibbler::createNewHead(int x, int y)
{
    Player head;

    head.setPos(std::make_pair(x, y));
    head.setTexturePath(std::filesystem::absolute(std::filesystem::path("Src/Games/Nibbler/Resources/Textures/Snake/SnakeHead.png")).string());
    head.setTermTexture('o', Color::TermColors::RED, Color::TermColors::BLACK);
    return head;
}

Player Nibbler::createNewTail(int x, int y)
{
    Player tail;

    tail.setPos(std::make_pair(x, y));
    tail.setTexturePath(std::filesystem::absolute(std::filesystem::path("Src/Games/Nibbler/Resources/Textures/Snake/SnakeTail.png")).string());
    tail.setTermTexture('.', Color::TermColors::GREEN, Color::TermColors::BLACK);
    return tail;
}

Object Nibbler::createNewFruit(int x, int y)
{
    Object fruit(Object::ENTITY_TYPE::BONUS);

    fruit.setPos(std::make_pair(x, y));
    fruit.setTermTexture('*', Color::TermColors::YELLOW, Color::TermColors::BLACK);
    return fruit;
}

Object Nibbler::createNewWall(int x, int y)
{
    Object wall(Object::ENTITY_TYPE::WALL);

    wall.setPos(std::make_pair(x, y));
    wall.setTermTexture(' ', Color::TermColors::BLACK, Color::TermColors::WHITE);
    return wall;
}

void Nibbler::initEntities(std::vector<std::shared_ptr<IEntity>> &entities)
{
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < (GRID_WIDTH - (GRID_WIDTH / 4)); j++) {
            if (i == 0 || i == GRID_HEIGHT - 1 || j == 0 || j == (GRID_WIDTH - (GRID_WIDTH / 4)) - 1) {
                std::shared_ptr<Object> wall = std::make_shared<Object>(createNewWall(j, i));
                entities.push_back(wall);
                _walls.push_back(wall);
            }
        }
    }

    Player head = createNewHead(GRID_WIDTH / 2, GRID_HEIGHT / 2 + 1);
    Player tail1 = createNewTail(GRID_WIDTH / 2, GRID_HEIGHT / 2);
    Player tail2 = createNewTail(GRID_WIDTH / 2, GRID_HEIGHT / 2 - 1);
    Player tail3 = createNewTail(GRID_WIDTH / 2, GRID_HEIGHT / 2 - 2);

    std::shared_ptr<Player> headPtr = std::make_shared<Player>(head);
    std::shared_ptr<Player> tail1Ptr = std::make_shared<Player>(tail1);
    std::shared_ptr<Player> tail2Ptr = std::make_shared<Player>(tail2);
    std::shared_ptr<Player> tail3Ptr = std::make_shared<Player>(tail3);


    _snake.push_back(headPtr);
    _snake.push_back(tail1Ptr);
    _snake.push_back(tail2Ptr);
    _snake.push_back(tail3Ptr);

    entities.push_back(headPtr);
    entities.push_back(tail1Ptr);
    entities.push_back(tail2Ptr);
    entities.push_back(tail3Ptr);
    entities.push_back(_fruit);
}

int Nibbler::getClockTimeMS()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _clock).count();
}

void Nibbler::resetClock()
{
    _clock = std::chrono::high_resolution_clock::now();
}

void Nibbler::manageKeyEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities)
{
    switch (event.key.key) {
        case 'Z':
            if (_lastDir != IEntity::Direction::DOWN)
                _snake.front()->setDirection(IEntity::Direction::UP);
            break;
        case 'Q':
            if (_lastDir != IEntity::Direction::RIGHT)
                _snake.front()->setDirection(IEntity::Direction::LEFT);
            break;
        case 'S':
            if (_lastDir != IEntity::Direction::UP)
                _snake.front()->setDirection(IEntity::Direction::DOWN);
            break;
        case 'D':
            if (_lastDir != IEntity::Direction::LEFT)
                _snake.front()->setDirection(IEntity::Direction::RIGHT);
            break;
    }
}

void Nibbler::manageEvent(Arcade::Evt &event, std::vector<std::shared_ptr<IEntity>> &entities)
{
    if (event.evt_type == Arcade::Evt::EvtType::KEY)
        manageKeyEvent(event, entities);
}

void Nibbler::update(std::vector<std::shared_ptr<IEntity>> &entities, std::stack<Arcade::Evt> &events)
{
    while (events.size() > 0) {
        manageEvent(events.top(), entities);
        events.pop();
    }

    if (_gameState == GameState::RUNNING) {
        moveSnake();
        snakeIsOnAFruit(entities);
    }

    if (snakeIsDeadCollision())
        _gameState = GameState::STOPPED;

    if (_snake.size() == GRID_HEIGHT * GRID_WIDTH)
        nextLevel(entities);
}

std::pair<int, int> Nibbler::getNextPos(std::pair<int, int> pos, IEntity::Direction dir)
{
    switch (dir) {
        case IEntity::Direction::UP:
            return std::make_pair(pos.first - 1, pos.second);
        case IEntity::Direction::DOWN:
            return std::make_pair(pos.first + 1, pos.second);
        case IEntity::Direction::LEFT:
            return std::make_pair(pos.first, pos.second - 1);
        case IEntity::Direction::RIGHT:
            return std::make_pair(pos.first, pos.second + 1);
        default:
            return pos;
    }
}

void Nibbler::moveSnake()
{
    if (getClockTimeMS() * _speed > 200) {
        resetClock();
        IEntity::Direction dirPrev = _snake.front()->getDirection();
        IEntity::Direction dirBuffer;
        _lastTailDir = _snake.back()->getDirection();
        _lastTailPos = _snake.back()->getPos();
        _lastDir = _snake.front()->getDirection();
        for (auto &it: _snake) {
            dirBuffer = it->getDirection();
            it->setPos(getNextPos(it->getPos(), dirBuffer));
            it->setDirection(dirPrev);
            dirPrev = dirBuffer;
            if (it->getPos().first < 0 || it->getPos().first > GRID_WIDTH || it->getPos().second < 0 || it->getPos().second > GRID_HEIGHT) {
                _gameState = GameState::STOPPED;
            }
        }
    }
}

bool Nibbler::snakeIsDeadCollision()
{
    for (auto &it: _snake) {
        if (it != _snake.front() && it->getPos() == _snake.front()->getPos())
            return true;
    }
    for (auto &it: _walls) {
        if (_snake.front()->getPos() == it->getPos())
            return true;
    }
    return false;
}

bool Nibbler::snakeIsOnAFruit(std::vector<std::shared_ptr<IEntity>> &entities)
{
    if (_snake.front()->getPos() == _fruit->getPos()) {
        Player tail = createNewTail(_lastTailPos.first, _lastTailPos.second);
        tail.setDirection(_lastTailDir);
        std::shared_ptr<Player> tailPtr = std::make_shared<Player>(tail);
        _snake.push_back(tailPtr);
        entities.push_back(tailPtr);
        _score += 2;
        _fruit->setPos(std::make_pair((rand() % ((GRID_WIDTH - (GRID_WIDTH / 4)) - 2)) + 1, (rand() % ((GRID_HEIGHT) - 2)) + 1));
        return true;
    }
    return false;
}

void Nibbler::nextLevel(std::vector<std::shared_ptr<IEntity>> &entities)
{
    _speed *= 1.5;

    _snake.clear();
    entities.clear();
    initEntities(entities);
}

void Nibbler::start()
{
    _gameState = GameState::RUNNING;
}

std::string Nibbler::getLibraryName() const
{
    return "Nibbler";
}

IGame::GameState Nibbler::getState() const
{
    return _gameState;
}

void Nibbler::setState(GameState state)
{
    _gameState = state;
}

int Nibbler::getScore() const
{
    return _score;
}

bool Nibbler::getIsGameOver()
{
    return _gameState == GameState::STOPPED;
}
