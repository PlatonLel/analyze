cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(testAnalyze)

# Добавляем поддиректорию Linalg
add_subdirectory(Linalg)

# Добавляем исполняемый файл теста
add_executable(test Source/test.cpp Complex/Source/Complex.cpp)

# Указываем, что test должен видеть заголовочные файлы из Complex и Linalg
target_include_directories(test PUBLIC Complex/Include)

# Линкуем библиотеку Linalg к test
target_link_libraries(test PRIVATE Linalg)
