add_library(ssGA STATIC
        src/Chromosome.cpp)

target_include_directories(ssGA PUBLIC
        include)

target_link_libraries(ssGA PUBLIC fmt)

add_subdirectory(tests)