
project(square)

set(HEDEAR_FILES Square.h)
set(SOURCE_FILES Square.cpp )


add_library(libsquare STATIC ${SOURCE_FILES} )
target_include_directories(libsquare PUBLIC .)
target_link_libraries(libsquare libpoint)
add_executable(square ${SOURCE_FILES} main.cpp)


target_link_libraries(square libsquare)


