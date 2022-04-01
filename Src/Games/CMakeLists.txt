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

    add_library(${create_arcade_game_GAME_NAME} SHARED ${create_arcade_game_SRC})

    target_link_libraries(${create_arcade_game_GAME_NAME} PRIVATE ArcadeCommonInterface)
    set_target_properties(${create_arcade_game_GAME_NAME} PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    )
    target_include_directories(${create_arcade_game_GAME_NAME} PRIVATE ${create_arcade_game_INCLUDE_DIRS})

endfunction()

add_subdirectory(Nibbler)
add_subdirectory(Pacman)
