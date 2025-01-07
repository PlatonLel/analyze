cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(analyze)

add_subdirectory(linalg)

add_executable(analyze Source/analyze.cpp)

target_link_libraries(analyze PRIVATE Linalg)
