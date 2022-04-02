/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#ifndef ARCAAAAAAAAAAAAAAAAADE_CORE_HPP
#define ARCAAAAAAAAAAAAAAAAADE_CORE_HPP

#include "IEntity.hpp"
#include "IGame.hpp"
#include "IGraph.hpp"
#include <vector>

class Core {
    public:
        Core();
        ~Core();
        void addEntity(IEntity *entity);
        void removeEntity(IEntity *entity);
        void update();
        void draw();
    private:
        std::vector<IEntity *> _entities;
        IGame *_game;
        template<typename T>
        IGraph<T>* _graph;

}

#endif//ARCAAAAAAAAAAAAAAAAADE_CORE_HPP
