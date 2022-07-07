file(GLOB test_FILES
        "*_tests.cpp"
        )

add_executable(tests_pHub ${test_FILES})
target_link_libraries(tests_pHub PUBLIC phub)
target_include_directories(tests_pHub PRIVATE ../../3rd_party)