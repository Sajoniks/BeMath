cmake_minimum_required(VERSION 3.14)

project(
    BeMath
    LANGUAGES CXX
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(third_party/googletest)
set_target_properties(gtest_main PROPERTIES FOLDER ThirdParty/GoogleTest)
set_target_properties(gtest PROPERTIES FOLDER ThirdParty/GoogleTest)
set_target_properties(gmock_main PROPERTIES FOLDER ThirdParty/GoogleTest)
set_target_properties(gmock PROPERTIES FOLDER ThirdParty/GoogleTest)
enable_testing()

add_subdirectory(classes)
add_subdirectory(math)