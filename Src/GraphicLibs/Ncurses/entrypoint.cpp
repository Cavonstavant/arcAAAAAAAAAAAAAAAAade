#include <iostream>
#include "IGraph.hpp"
#include "NcursesLibrary.hpp"

namespace Arcade
{
    static IGraph *GRAPH_INSTANCE = nullptr;

    extern "C" IGraph *getGraphInstance()
    {
        return GRAPH_INSTANCE;
    }

    [[gnu::constructor]] void libConstruct()
    {
        GRAPH_INSTANCE = new NcursesLibrary();
        std::cout << "sfml lib loaded" << std::endl;
    }

    [[gnu::destructor]] void libDestruct()
    {
        delete GRAPH_INSTANCE;
        std::cout << "sfml lib unloaded" << std::endl;
    }
}