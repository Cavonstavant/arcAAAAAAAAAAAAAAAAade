set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/Nibbler)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/Nibbler)

set(SRC
    ${SRC_ROOT}/entrypoint.cpp
    ${SRC_ROOT}/Nibbler.cpp
    ${SRC_ROOT}/Nibbler.hpp
)

create_arcade_game(
        GAME_NAME arcade_nibbler
        SRC ${SRC}
        INCLUDE_DIRS ${INCLUDE_ROOT}
)