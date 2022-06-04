cmake_minimum_required(VERSION 3.18.4)
project(Algorithms_HW3)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(graph_lib)

add_executable(${PROJECT_NAME} main.cpp)

#target_include_directories(${PROJECT_NAME} PUBLIC ${GRAPH_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE graph_lib)

add_subdirectory(test)
