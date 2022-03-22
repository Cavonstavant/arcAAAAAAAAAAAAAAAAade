cmake_minimum_required(VERSION 3.17)
project(ArcadeCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR})
set(SOURCE_ROOT ${PROJECT_SOURCE_DIR})

set(TARGET_LIB_NAME libarcade_core)
set(TARGET_EXEC_NAME arcade)

set(SRC
    ${INCLUDE_ROOT}/Core.hpp
    ${INCLUDE_ROOT}/AEntity.hpp
    ${INCLUDE_ROOT}/Core.cpp
    ${INCLUDE_ROOT}/AEntity.cpp
    ${INCLUDE_ROOT}/Exception.cpp
    ${INCLUDE_ROOT}/Exception.hpp)

set_target_properties(${TARGET_LIBNAME} PROPERTIES LINKER_LANGUAGE CXX)

add_library(${TARGET_LIB_NAME} ${SRC})

target_link_libraries(${TARGET_LIB_NAME} PRIVATE ArcadeCommonInterface dl)

target_include_directories(${TARGET_LIB_NAME} PRIVATE ${SRC_ROOT})
include_directories(../CommonInterface/include)

add_executable(${TARGET_EXEC_NAME} ${SOURCE_ROOT}/EntryPoint.cpp)

target_link_libraries(${TARGET_EXEC_NAME} PRIVATE ${TARGET_LIB_NAME})

target_include_directories(${TARGET_EXEC_NAME} PRIVATE ${INCLUDE_ROOT})

add_custom_command(TARGET ${TARGET_EXEC_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_EXEC_NAME}> ${PROJECT_SOURCE_DIR}
)
