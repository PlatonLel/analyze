cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(testAnalyze)

add_subdirectory(linalg/Linalg)

add_executable(test Source/test.cpp Complex/Source/Complex.cpp)

target_include_directories(test PUBLIC Complex/Include)

target_link_libraries(test PRIVATE Linalg)