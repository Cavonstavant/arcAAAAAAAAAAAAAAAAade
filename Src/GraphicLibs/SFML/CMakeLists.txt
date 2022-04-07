find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/SFML)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/SFML)

set(SRC
    ${SRC_ROOT}/EntryPoint.cpp
    ${SRC_ROOT}/SfmlLibrary.cpp
    ${SRC_ROOT}/SfmlLibrary.hpp
)
#[[set(INCLUDE_DIRS ${INCLUDE_ROOT})]]

create_arcade_graph_lib(
    GRAPH_LIB_NAME SFML
    SRC ${SRC}
    INCLUDE_DIRS ${SRC_ROOT} ${INCLUDE_ROOT}
    DEPS ${SFML_LIBRARIES}
)
