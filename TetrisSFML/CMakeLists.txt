cmake_minimum_required(VERSION 3.8)

set(SRCS "main.cpp" "Tetris.cpp" "Tetromino.cpp")
set(HEADERS "Tetris.h" "Tetromino.h" "tetrominsmap.h")

include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include")

set(SFML_COMPONENTS audio network graphics window system)
set(SFML_LINKED_LIBRARIES sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

if (WIN32)
    set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/lib/cmake")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/lib/cmake/SFML")
    find_package(SFML 2.5.1 REQUIRED COMPONENTS ${SFML_COMPONENTS})
elseif (UNIX)
    find_package(SFML 2.5.1 REQUIRED COMPONENTS ${SFML_COMPONENTS})
endif ()

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${SFML_LINKED_LIBRARIES})
