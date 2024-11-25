cmake_minimum_required(VERSION 3.5)
project("Data Structures" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(data_structures src/main.cpp)