project(Array2D)

set(HEDEAR_FILES Array2D.h)
set(SOURCE_FILES Array2D.cpp)

add_library(libarray2d STATIC ${SOURCE_FILES})
target_include_directories(libarray2d PUBLIC .)

add_executable(Array2D ${SOURCE_FILES} main.cpp)

target_link_libraries(Array2D libarray2d)