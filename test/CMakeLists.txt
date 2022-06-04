cmake_minimum_required(VERSION 3.18.4)
project(tests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest CONFIG REQUIRED)
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTest gtest_main)

message("INCLUDES = " ${GTest_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} tests.cpp)
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)



