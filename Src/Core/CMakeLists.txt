set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/Core)
set(SOURCE_ROOT ${PROJECT_SOURCE_DIR}/Src/Core)
set(CORE_EVENT_SRC ${SOURCE_ROOT}/CoreEvents)

set(TARGET_LIB_NAME libarcade_core)
set(TARGET_EXEC_NAME arcade)

set(COMMON_GAME_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Src/Games/Common)
set(COMMON_GAME_SOURCES
    ${COMMON_GAME_INCLUDE_DIR}/AEntity.hpp
    ${COMMON_GAME_INCLUDE_DIR}/AEntity.cpp
    ${COMMON_GAME_INCLUDE_DIR}/Button.cpp
    ${COMMON_GAME_INCLUDE_DIR}/Button.hpp
    ${COMMON_GAME_INCLUDE_DIR}/Enemy.cpp
    ${COMMON_GAME_INCLUDE_DIR}/Enemy.hpp
    ${COMMON_GAME_INCLUDE_DIR}/Object.cpp
    ${COMMON_GAME_INCLUDE_DIR}/Object.hpp
    ${COMMON_GAME_INCLUDE_DIR}/Player.cpp
    ${COMMON_GAME_INCLUDE_DIR}/Player.hpp
    ${COMMON_GAME_INCLUDE_DIR}/TextEntity.cpp
    ${COMMON_GAME_INCLUDE_DIR}/TextEntity.hpp
)

set(SRC
        ${INCLUDE_ROOT}/Core.hpp
        ${INCLUDE_ROOT}/Core.cpp
        ${INCLUDE_ROOT}/Exception.cpp
        ${INCLUDE_ROOT}/Exception.hpp
        ${INCLUDE_ROOT}/Logger.hpp
        ${INCLUDE_ROOT}/Logger.cpp
        ${INCLUDE_ROOT}/LibManager.cpp
        ${INCLUDE_ROOT}/LibManager.hpp
        ${INCLUDE_ROOT}/MainMenu/MainMenu.cpp
        ${INCLUDE_ROOT}/MainMenu/MainMenu.hpp
        ${COMMON_GAME_SOURCES}
        ${CORE_EVENT_SRC}/CoreEvents.cpp
)

set_target_properties(${TARGET_LIBNAME} PROPERTIES LINKER_LANGUAGE CXX)

add_library(${TARGET_LIB_NAME} ${SRC})

target_link_libraries(${TARGET_LIB_NAME} PRIVATE ArcadeCommonInterface dl)

target_include_directories(${TARGET_LIB_NAME} PRIVATE ${SRC_ROOT})
target_include_directories(${TARGET_LIB_NAME} PRIVATE ../Games/Common)

add_executable(${TARGET_EXEC_NAME} ${SOURCE_ROOT}/EntryPoint.cpp)

include_directories(
        ${PROJECT_SOURCE_DIR}/Src/CommonInterface/include
        ${PROJECT_SOURCE_DIR}/Src/Games/Common
)

target_link_libraries(${TARGET_EXEC_NAME} PRIVATE ${TARGET_LIB_NAME})

target_include_directories(${TARGET_EXEC_NAME} PRIVATE ${INCLUDE_ROOT})


add_custom_command(TARGET ${TARGET_EXEC_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_EXEC_NAME}> ${PROJECT_SOURCE_DIR}
        )
