set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/Common/)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/Src/Games/Common/)

set(TARGET_LIB_NAME graphic_lib_common)

set(SRC
    ${INCLUDE_ROOT}/AEntity.hpp
    ${INCLUDE_ROOT}/AEntity.cpp
    ${INCLUDE_ROOT}/Button.cpp
    ${INCLUDE_ROOT}/Button.hpp
    ${INCLUDE_ROOT}/Enemy.cpp
    ${INCLUDE_ROOT}/Enemy.hpp
    ${INCLUDE_ROOT}/Object.cpp
    ${INCLUDE_ROOT}/Object.hpp
    ${INCLUDE_ROOT}/Player.cpp
    ${INCLUDE_ROOT}/Player.hpp
    ${INCLUDE_ROOT}/TextEntity.cpp
    ${INCLUDE_ROOT}/TextEntity.hpp
)

add_library(${TARGET_LIB_NAME} ${SRC})

set_target_properties(${TARGET_LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${TARGET_LIB_NAME} ArcadeCommonInterface)
target_include_directories(${TARGET_LIB_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Src/Games/Common)
