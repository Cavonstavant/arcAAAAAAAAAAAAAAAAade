#include <iostream>
#include "IGraph.hpp"
#include "SfmlLibrary.hpp"

namespace Arcade
{
    static IGraph<float> *GRAPH_INSTANCE = nullptr;

    extern "C" IGraph<float> *getGraphInstance()
    {
        return GRAPH_INSTANCE;
    }

    [[gnu::constructor]] void libConstruct()
    {
        GRAPH_INSTANCE = new SfmlLibrary();
        std::cout << "sfml lib loaded" << std::endl;
    }

    [[gnu::destructor]] void libDestruct()
    {
        delete GRAPH_INSTANCE;
        std::cout << "sfml lib unloaded" << std::endl;
    }
}