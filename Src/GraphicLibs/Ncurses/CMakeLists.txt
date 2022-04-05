set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/Ncurses)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/Ncurses)

set(SRC
    ${SRC_ROOT}/entrypoint.cpp
    ${SRC_ROOT}/NcursesLibrary.cpp
    ${SRC_ROOT}/NcursesLibrary.hpp
)

set(INCLUDE_DIRS ${INCLUDE_ROOT})

create_arcade_graph_lib(
    GRAPH_LIB_NAME ncurses
    INCLUDE_DIRS ${SRC_ROOT} ${INCLUDE_ROOT}
    SRC ${SRC}
)
