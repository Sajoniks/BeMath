add_library(classes STATIC
    include/bemath/classes.h
    src/vector.cpp
)
add_library(bemath::classes ALIAS classes)

set_target_properties(classes PROPERTIES FOLDER BeMath)

target_include_directories(classes
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(classes
    PRIVATE bemath::math
)

add_subdirectory(test)