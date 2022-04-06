/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "Event.hpp"
#include <stack>
#include <random>
#include <ctime>

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

void Nibbler::init(std::vector<std::shared_ptr<IEntity>> &entities)
{
    srand((unsigned)time(NULL));
    _gameState = GameState::LOADED;
    _lastTailDir = IEntity::Direction::RIGHT;
    _lastTailPos = std::make_pair(0, 0);

    Player head;
    Player tail1;
    Player tail2;
    Player tail3;

    head.setPos(std::make_pair(GRID_WIDTH / 2 + 1, GRID_HEIGHT / 2));
    tail1.setPos(std::make_pair(GRID_WIDTH / 2, GRID_HEIGHT / 2));
    tail2.setPos(std::make_pair(GRID_WIDTH / 2 - 1, GRID_HEIGHT / 2));
    tail3.setPos(std::make_pair(GRID_WIDTH / 2 - 2, GRID_HEIGHT / 2));
    _fruit->setPos(std::make_pair(rand() % GRID_WIDTH, rand() % GRID_HEIGHT));

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
            if (_snake.front()->getDirection() != IEntity::Direction::DOWN)
                _snake.front()->setDirection(IEntity::Direction::UP);
            break;
        case 'Q':
            if (_snake.front()->getDirection() != IEntity::Direction::RIGHT)
                _snake.front()->setDirection(IEntity::Direction::LEFT);
            break;
        case 'S':
            if (_snake.front()->getDirection() != IEntity::Direction::UP)
                _snake.front()->setDirection(IEntity::Direction::DOWN);
            break;
        case 'D':
            if (_snake.front()->getDirection() != IEntity::Direction::LEFT)
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
}

static std::pair<int, int> getNextPos(std::pair<int, int> pos, int dir)
{
    switch (dir) {
        case IEntity::Direction::UP:
            return std::make_pair(pos.first, pos.second - 1);
        case IEntity::Direction::DOWN:
            return std::make_pair(pos.first, pos.second + 1);
        case IEntity::Direction::LEFT:
            return std::make_pair(pos.first - 1, pos.second);
        case IEntity::Direction::RIGHT:
            return std::make_pair(pos.first + 1, pos.second);
        default:
            return pos;
    }
}

void Nibbler::moveSnake()
{
    if (getClockTimeMS() > 500) {
        resetClock();
        IEntity::Direction dirPrev = _snake.front()->getDirection();
        IEntity::Direction dirBuffer;
        _lastTailDir = _snake.back()->getDirection();
        _lastTailPos = _snake.back()->getPos();
        for (auto &it : _snake) {
            dirBuffer = it->getDirection();
            it->setPos(getNextPos(it->getPos(), dirBuffer));
            it->setDirection(dirPrev);
            dirPrev = dirBuffer;
            // if (it->getPos().first < 0 || it->getPos().first >= GRID_WIDTH || it->getPos().second < 0 || it->getPos().second >= GRID_HEIGHT) {
            //     _gameState = GameState::STOPPED;
            // }
        }
    }
}

bool Nibbler::snakeIsOnAFruit(std::vector<std::shared_ptr<IEntity>> &entities)
{
    if (_snake.front()->getPos() == _fruit->getPos()) {
        std::shared_ptr<Player> tail;
        tail->setPos(_lastTailPos);
        tail->setDirection(_lastTailDir);
        _snake.push_back(tail);
        entities.push_back(tail);
        _fruit->setPos(std::make_pair(rand() % GRID_WIDTH, rand() % GRID_HEIGHT));
        return true;
    }
    return false;
}

void Nibbler::start()
{
    _gameState = GameState::RUNNING;
}

std::string Nibbler::getLibraryName() const
{
    return "Nibbler";
}
