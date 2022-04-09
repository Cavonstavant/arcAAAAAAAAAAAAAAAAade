#include "IGraph.hpp"
#include "NcursesLibrary.hpp"
#include <iostream>

namespace Arcade {
    static IGraph *GRAPH_INSTANCE = nullptr;

    extern "C" IGraph *getGraphInstance()
    {
        return GRAPH_INSTANCE;
    }

    [[gnu::constructor]] void libConstruct()
    {
        GRAPH_INSTANCE = new NcursesLibrary();
        std::cout << "NcursesLibrary loaded" << std::endl;
    }

    [[gnu::destructor]] void libDestruct()
    {
        delete GRAPH_INSTANCE;
        std::cout << "NcursesLibrary unloaded" << std::endl;
    }
}// namespace Arcade
