set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/MainMenu)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/MainMenu)

set(SRC
    ${SRC_ROOT}/MainMenu.cpp
    ${SRC_ROOT}/MainMenu.hpp
)

create_arcade_game(
        GAME_NAME arcade_main_menu
        SRC ${SRC}
        INCLUDE_DIRS ${INCLUDE_ROOT}
)
