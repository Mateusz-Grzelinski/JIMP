
project(parent)

set(HEDEAR_FILES Parent.h)
set(SOURCE_FILES Parent.cpp)

add_library(libparent STATIC ${SOURCE_FILES})
target_include_directories(libparent PUBLIC .)

target_link_libraries(libparent libchild )

add_executable(parent ${SOURCE_FILES} )

target_link_libraries(parent libparent)

