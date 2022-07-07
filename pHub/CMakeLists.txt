add_library(phub STATIC
        src/phub.cpp)

target_include_directories(phub PUBLIC include)

target_link_libraries(phub PUBLIC
        ssGA)

add_subdirectory(tests)