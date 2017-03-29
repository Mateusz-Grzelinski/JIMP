
project(child)

set(HEDEAR_FILES Child.h)
set(SOURCE_FILES Child.cpp)

add_library(libchild STATIC ${SOURCE_FILES})
target_include_directories(libchild PUBLIC .)

add_executable(child ${SOURCE_FILES} )

target_link_libraries(child libchild)

