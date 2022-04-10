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
    }

    [[gnu::destructor]] void libDestruct()
    {
        delete GRAPH_INSTANCE;
    }
}// namespace Arcade
