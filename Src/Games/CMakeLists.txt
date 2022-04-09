set(COMMON_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/Common/)
set(COMMON_SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/Common/)
function(create_arcade_game)
    set(game_name GAME_NAME)
    set(sources INCLUDE_DIRS SRC)
    cmake_parse_arguments(create_arcade_game "" "${game_name}" "${sources}" ${ARGN})

    if (NOT DEFINED create_arcade_game_GAME_NAME)
        message(FATAL_ERROR "create_arcade_game: GAME_NAME not defined")
    endif()
    if (NOT DEFINED create_arcade_game_SRC)
        message(FATAL_ERROR "create_arcade_game: SRC not defined")
    endif()

    set(LIB_SOURCES
        ${create_arcade_game_SRC}
        ${COMMON_INCLUDE_ROOT}/AEntity.hpp
        ${COMMON_INCLUDE_ROOT}/AEntity.cpp
        ${COMMON_INCLUDE_ROOT}/Button.cpp
        ${COMMON_INCLUDE_ROOT}/Button.hpp
        ${COMMON_INCLUDE_ROOT}/Enemy.cpp
        ${COMMON_INCLUDE_ROOT}/Enemy.hpp
        ${COMMON_INCLUDE_ROOT}/Object.cpp
        ${COMMON_INCLUDE_ROOT}/Object.hpp
        ${COMMON_INCLUDE_ROOT}/Player.cpp
        ${COMMON_INCLUDE_ROOT}/Player.hpp
        ${COMMON_INCLUDE_ROOT}/TextEntity.cpp
        ${COMMON_INCLUDE_ROOT}/TextEntity.hpp
        )

    add_library(${create_arcade_game_GAME_NAME} SHARED ${LIB_SOURCES})

    target_link_libraries(${create_arcade_game_GAME_NAME} ArcadeCommonInterface)

    set_target_properties(${create_arcade_game_GAME_NAME} PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    )
    target_include_directories(${create_arcade_game_GAME_NAME} PRIVATE Common/)
    target_include_directories(${create_arcade_game_GAME_NAME} PRIVATE ${create_arcade_game_INCLUDE_DIRS})

endfunction()

#add_subdirectory(Common)
add_subdirectory(Nibbler)
add_subdirectory(Pacman)
