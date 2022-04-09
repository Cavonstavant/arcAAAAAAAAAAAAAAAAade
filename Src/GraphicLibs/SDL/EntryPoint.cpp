#include "IGraph.hpp"
#include "SdlLibrary.hpp"
#include <iostream>

namespace Arcade {
static IGraph *GRAPH_INSTANCE = nullptr;

extern "C" IGraph *getGraphInstance()
{
    return GRAPH_INSTANCE;
}

[[gnu::constructor]] void libConstruct()
{
    GRAPH_INSTANCE = new SdlLibrary();
}

[[gnu::destructor]] void libDestruct()
{
    delete GRAPH_INSTANCE;
}
}// namespace Arcade
