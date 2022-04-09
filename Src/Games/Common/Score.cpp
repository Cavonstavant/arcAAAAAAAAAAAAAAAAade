/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Score
*/

#include "Score.hpp"

Score::Score() : Object(ENTITY_TYPE::SCORE)
{
    _score = 0;
}

Score::~Score()
{
}

unsigned int Score::getScore() const
{
    return _score;
}

void Score::setScore(unsigned int score)
{
    _score = score;
}
