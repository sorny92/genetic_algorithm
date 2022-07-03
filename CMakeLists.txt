cmake_minimum_required(VERSION 3.22)
project(p_hub_genetic_algorithm CXX)

add_subdirectory(ssGA)
add_executable(phub
        phub.cpp)
target_link_libraries(phub PRIVATE
        ssGA)
