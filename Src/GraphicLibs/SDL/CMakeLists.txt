find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/SDL)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/GraphicLibs/SDL)

set(SRC
    ${SRC_ROOT}/entrypoint.cpp
    ${SRC_ROOT}/SdlLibrary.cpp
    ${SRC_ROOT}/SdlLibrary.hpp
)

set(INCLUDE_DIRS ${INCLUDE_ROOT})

create_arcade_graph_lib(
    GRAPH_LIB_NAME SDL
    INCLUDE_DIRS ${SRC_ROOT} ${INCLUDE_ROOT}
    SRC ${SRC}
    DEPS SDL2::Main SDL2::Image SDL2::TTF
)
