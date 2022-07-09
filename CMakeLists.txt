cmake_minimum_required(VERSION 3.22)
project(p_hub_genetic_algorithm CXX)


add_subdirectory(ssGA)
add_subdirectory(pHub)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC ssGA)