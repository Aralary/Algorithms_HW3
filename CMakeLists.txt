cmake_minimum_required(VERSION 3.18.4)
project(Algorithms_HW3)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/graph.cpp
        )
add_library(graph STATIC ${SOURCES})

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(graph PUBLIC headers)
target_link_libraries(${PROJECT_NAME} graph)
add_subdirectory(test)