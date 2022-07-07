file(GLOB test_FILES
        "*_tests.cpp"
        )

add_executable(tests_ssGA ${test_FILES})
target_link_libraries(tests_ssGA PRIVATE ssGA)
target_include_directories(tests_ssGA PRIVATE ../../3rd_party)