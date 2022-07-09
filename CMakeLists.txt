cmake_minimum_required(VERSION 3.22)
project(p_hub_genetic_algorithm CXX)
set (CMAKE_CXX_STANDARD 20)

add_subdirectory(3rd_party/fmt)
add_subdirectory(ssGA)
add_subdirectory(pHub)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC ssGA tbb)