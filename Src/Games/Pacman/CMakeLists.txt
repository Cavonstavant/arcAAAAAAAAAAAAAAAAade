set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/Pacman)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/Pacman)

set(SRC
    ${SRC_ROOT}/Pacman.cpp
    ${SRC_ROOT}/Pacman.hpp
    ${SRC_ROOT}/entryPoint.cpp
)

create_arcade_game(
    GAME_NAME arcade_pacman
    SRC ${SRC}
    INCLUDE_DIRS ${INCLUDE_ROOT}
)
