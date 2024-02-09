find_library(googletest GTest)

add_executable(vector_test vector_test.cc)
target_link_libraries(vector_test 
    PRIVATE GTest::gtest_main
    PRIVATE bemath::classes
)
set_target_properties(vector_test PROPERTIES FOLDER BeMath/Tests)

include(GoogleTest)
gtest_discover_tests(vector_test)