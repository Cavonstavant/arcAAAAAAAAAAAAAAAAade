/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#ifndef ARCAAAAAAAAAAAAAAAAADE_CORE_HPP
#define ARCAAAAAAAAAAAAAAAAADE_CORE_HPP

/// \file Core.hpp

#include "IEntity.hpp"
#include "IGame.hpp"
#include "IGraph.hpp"
#include "Event.hpp"
#include "MainMenu/MainMenu.hpp"
#include "LibManager.hpp"
#include "Exception.hpp"
#include <vector>
#include <filesystem>

/// \brief Core class that the transfer of data between games and displays
class Core {
    public:
        /// \brief Represent the Core state
        enum class State {
            /// \brief The Core is in the main menu
            MAIN_MENU,
            /// \brief The Core is in a game
            GAME,
            /// \brief The Core is in the pause menu or the game over menu
            EXIT
        };

        /// \brief Creating a core without at least a path to a library should be impossible
        Core() = delete;

        /// \brief Creating a core with a variable number of paths to libraries
        explicit Core(std::vector<std::string> libsPath);

        /// \brief Dtor
        inline ~Core() { _libManager.closeAllLibs(); }

        /// \brief Construct a core with an other core should not be possible
        Core(Core const &) = delete;

        /// \brief Assign a core to another should not be possible
        Core& operator=(Core const &) = delete;

        /// \brief Add an entity to the entities collection
        /// \param entity The entity to add
        void addEntity(const std::shared_ptr<IEntity>& entity);

        /// \brief Remove an entity to the entities collection
        /// \param entity The entity collection to remove
        void removeEntity(const std::shared_ptr<IEntity>& entity);

        /// \brief Get the current state of the core
        /// \return The current state of the core
        [[nodiscard]] inline State getState() const { return _state; }

        /// \brief Set the current state of the core
        /// \param state The new state of the core
        inline void setState(State state) { _state = state; }

        /// \brief Get the current game of the core
        /// \return The current game of the core
        [[nodiscard]] inline IGame* getGame() const { return _game; }

        /// \brief Set the current game of the core
        /// \param game The new game of the core
        inline void setGame(IGame* game) { _game = game; }

        void setGame(const std::string& libPath);

        /// \brief Get the current graphical display of the core
        /// \return The current graphical display of the core
        [[nodiscard]] inline IGraph* getGraph() const { return _graph; }

        /// \brief Set the current graphical display of the core
        /// \param graph The new graphical display of the core
        inline void setGraph(IGraph* graph)  { _graph = graph; }

        void setGraph(const std::string& libPath);

        /// \brief Get the current event
        /// \return The current event
        [[nodiscard]] inline Arcade::Evt getLastEvent() const { return _event.top(); }

        /// \brief Pop the last event on the stack
        /// \warning Not setting up any graphical display before polling any event will result in an <b>undefined behavior</b>
        inline void popEvent() { return _event.pop(); }

        /// \brief Set the the current event
        /// \param event The new last event produced by the graphical display
        /// \note if the event is of type <b>WINDOW_CLOSE</b> while the core is in the <b>GAME</b>, the core will be set to <b>MENU</b> state
        /// \note if the event is of type <b>WINDOW_CLOSE</b>, the core will be set to <b>EXIT</b> state
        inline void setEvent(Arcade::Evt event) { _event.push(event); }

        /// \brief Update the data of all entities by passing them to the game
        void update();

        /// \brief Update the graphical interface by passing all the entities to the graph
        void draw();

        /// \brief Process the events retrieved inside the graphical display
        /// \note This function is called after the graphical display has been updated
        /// \note Events can be retrieved by using <b>getLastEvent()</b>, <b>popEvent()</b> and <b>setEvent(Arcade::Evt)</b>
        /// \warning Not setting up any graphical display before polling any event will result in an <b>undefined behavior</b>
        void processEvents();


        std::string getFutureGraph() { return _futureGraph; }

        /// \brief Set the future graphical display to be used
        void setFutureGraph(std::string &futureGraph) { _futureGraph = futureGraph; }

        std::string getFutureGame() { return _futureGame; }

        void setFutureGame(std::string &futureGame) { _futureGame = futureGame; }

    private:
        /// \brief The library manager containing all the libraries
        LibManager _libManager;

        /// \brief The entities collection
        std::vector<std::shared_ptr<IEntity>> _entities;

        /// \brief The main menu
        MainMenu _mainMenu;

        /// \brief The game currently running
        IGame *_game;

        /// \brief The game future library path to be loaded, null terminated
        /// \note This is set when loading a game either by the main menu or inside the game itself
        /// \note If there is no graphical lib to be loaded, _futureGame will be empty
        std::string _futureGame;

        /// \brief The graphical interface currently running
        /// \note Will be filled with the instance retrieved from the graphical library passed by argument (argv[1])
        IGraph *_graph;

        /// \brief The future graphical library path, null terminated
        /// \note This is set when loading a graphical interface either by the main menu or inside the game itself
        /// \note If there is no graphical lib to be load, _futureGraph will be empty
        std::string _futureGraph;

        /// \brief The current event to be processed
        std::stack<Arcade::Evt> _event;

        /// \brief The current state of the core
        State _state;

        void coreEventSwitchGame(const std::string &key);

        void coreEventSwitchGraph(const std::string &key);

        void manageCoreKeyEvents(std::string &key);
};

#endif//ARCAAAAAAAAAAAAAAAAADE_CORE_HPP
