add_library(ssGA STATIC
        src/Chromosome.cpp)

target_include_directories(ssGA PUBLIC
        include)

add_subdirectory(tests)