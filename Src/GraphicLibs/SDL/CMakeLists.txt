find_package(SDL2 REQUIRED)

set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/SDL)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/SDL)

set(SRC
    ${SRC_ROOT}/entrypoint.cpp
)

set(INCLUDE_DIRS ${INCLUDE_ROOT})

create_arcade_graph_lib(
    GRAPH_LIB_NAME SDL
    INCLUDE_DIRS ${SRC_ROOT} ${INCLUDE_ROOT}
    SRC ${SRC}
)