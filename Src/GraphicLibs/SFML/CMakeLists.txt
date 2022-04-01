find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/SFML)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/SFML)

set(SRC
    ${SRC_ROOT}/entrypoint.cpp
)

set(INCCLUDE_DIRS ${INCLUDE_ROOT})

create_arcade_graph_lib(
    GRAPH_LIB_NAME SFML
    INCLUDE_DIRS ${SRC_ROOT} ${INCLUDE_ROOT}
    SRC ${SRC}
    DEPS ${SFML_LIBRARIES}
)
