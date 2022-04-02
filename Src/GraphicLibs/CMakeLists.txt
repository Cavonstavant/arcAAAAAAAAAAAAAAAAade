function(create_arcade_graph_lib)
    set (graph_lib_name GRAPH_LIB_NAME)
    set (sources INCLUDE_DIRS SRC DEPS)
    cmake_parse_arguments(create_arcade_graph_lib "" "${graph_lib_name}" "${sources}" ${ARGN})

    if (NOT DEFINED create_arcade_graph_lib_GRAPH_LIB_NAME)
        message(FATAL_ERROR "create_arcade_graph_lib: GRAPH_LIB_NAME is not defined")
    endif()
    if (NOT DEFINED create_arcade_graph_lib_SRC)
        message(FATAL_ERROR "create_arcade_graph_lib: SRC is not defined")
    endif()

    set(SRC "${create_arcade_graph_lib_SRC}")
    set(LIB_NAME "${create_arcade_graph_lib_GRAPH_LIB_NAME}")
    set(INCLUDE_DIRS "${create_arcade_graph_lib_INCLUDE_DIRS}")
    set(DEPS "${create_arcade_graph_lib_DEPS}")

    add_library(${LIB_NAME} SHARED ${SRC})
    set_target_properties(${LIB_NAME} PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
    )
    target_include_directories(${LIB_NAME} PRIVATE ${INCLUDE_DIRS} ${SRC_DIR})
    target_link_libraries(${LIB_NAME} PRIVATE ArcadeCommonInterface ${DEPS})
endfunction()

add_subdirectory(Ncurses)
add_subdirectory(SDL)
add_subdirectory(SFML)
