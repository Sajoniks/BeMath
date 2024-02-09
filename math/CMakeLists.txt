add_library(math STATIC
    include/bemath/math.h
    src/math.cpp
)
add_library(bemath::math ALIAS math)

set_target_properties(math PROPERTIES FOLDER BeMath)

target_include_directories(math
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(test)