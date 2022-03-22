cmake_minimum_required(VERSION 3.17)

project(ArcadeCommonInterface LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/include)

set(SRC
    ${INCLUDE_ROOT}/IGame.hpp
    ${INCLUDE_ROOT}/IDisplay.hpp
    ${INCLUDE_ROOT}/IEntity.hpp
)

add_library(${PROJECT_NAME} INTERFACE ${SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME} INTERFACE ${INCLUDE_ROOT})