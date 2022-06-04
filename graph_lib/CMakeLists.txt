cmake_minimum_required(VERSION 3.2)
project(graph_lib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/ArcGraph.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/ListGraph.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/MatrixGraph.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/SetGraph.cpp
        )

set(INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/
        )

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(graph_lib PUBLIC ${INCLUDE_DIRS})

set(GRAPH_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(GRAPH_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
