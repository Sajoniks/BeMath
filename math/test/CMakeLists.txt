find_library(googletest GTest)

add_executable(math_test math_test.cc)
target_link_libraries(math_test
    PRIVATE GTest::gtest_main
    PRIVATE bemath::math
)
set_target_properties(math_test PROPERTIES FOLDER BeMath/Tests)

include(GoogleTest)
gtest_discover_tests(math_test)