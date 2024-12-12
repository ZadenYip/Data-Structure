cmake_minimum_required(VERSION 3.5)
project("Data Structures" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(data_structures src/main.cpp)
target_include_directories(data_structures PRIVATE ${PROJECT_SOURCE_DIR}/include)

# 添加测试
add_subdirectory(third_party/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()
add_executable(runTests
    test/test_main.cpp
    test/sort/test_sort.cpp
    src/graph/edge.cpp
    src/graph/edge.cpp
    src/graph/directed_graph.cpp
    src/graph/algorithm/shortest_path/dijkstra.cpp
    test/graph/test_directed_graph.cpp
    test/graph/algorithm/shortest_path/test_dijkstra.cpp
)
target_link_libraries(runTests gtest gtest_main)
target_include_directories(runTests PRIVATE ${PROJECT_SOURCE_DIR}/include)