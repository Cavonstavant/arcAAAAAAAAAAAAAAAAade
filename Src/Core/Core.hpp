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
#include "MainMenu/MainMenu.hpp"
#include "LibManager.hpp"
#include <vector>

class Core {
    public:
        /// \brief Creating a core without at least a path to a library should be impossible
        Core() = delete;

        /// \brief Creating a core with a variable number of paths to libraries
        Core(std::vector<std::string> libsPath);

        /// \brief Dtor
        ~Core() = default;

        /// \brief Construct a core with an other core should not be possible
        Core(Core const &) = delete;

        /// \brief Assign a core to another should not be possible
        Core& operator=(Core const &) = delete;

        /// \brief Add an entity to the entities collection
        /// \param entity The entity to add
        void addEntity(std::shared_ptr<IEntity> entity);

        /// \brief Remove an entity to the entites collection
        /// \param entity The entity collection to remove
        void removeEntity(std::shared_ptr<IEntity> entity);

        /// \brief Update the data of all entities by passing them to the game
        void update();

        /// \brief Update the graphical interface by passing all the entiteis to the graph
        void draw();
    private:
        /// \brief The library manager containing all the libraries
        LibManager _libManager;

        /// \brief The entities collection
        std::vector<std::shared_ptr<IEntity>> _entities;

        /// \brief The main menu
        MainMenu _mainMenu;

        /// \brief The game currently running
        IGame *_game;

        /// \brief The graphical interface currently running
        /// \note Will be filled with the instance retrieved from the graphical library passed by argument (argv[1])
        IGraph *_graph;
};

#endif//ARCAAAAAAAAAAAAAAAAADE_CORE_HPP
