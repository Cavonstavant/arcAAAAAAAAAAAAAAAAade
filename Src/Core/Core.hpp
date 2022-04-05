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
        Core() = default;
        ~Core() = default;
        Core(Core const &) = delete;
        Core& operator=(Core const &) = delete;
        void addEntity(std::shared_ptr<IEntity> entity);
        void removeEntity(std::shared_ptr<IEntity> entity);
        std::vector<std::shared_ptr<IEntity>>& getEntities();
        void update();
        void draw();
    private:
        std::vector<std::shared_ptr<IEntity>> _entities;
        IGame *_game;
};

#endif//ARCAAAAAAAAAAAAAAAAADE_CORE_HPP
