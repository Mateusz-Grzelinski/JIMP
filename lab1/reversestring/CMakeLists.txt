project(reversestring)

set(HEDEAR_FILES reverse.h)
set(SOURCE_FILES reverse.cpp)

add_library(libreversestring STATIC ${SOURCE_FILES})
target_include_directories(libreversestring PUBLIC .)

add_executable(reversestring ${SOURCE_FILES} main.cpp)

target_link_libraries(reversestring libreversestring)
