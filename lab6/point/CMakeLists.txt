
project(point2)

set(HEDEAR_FILES Point2.h)
set(SOURCE_FILES Point2.cpp)

add_library(libpoint2 STATIC ${SOURCE_FILES})
target_include_directories(libpoint2 PUBLIC .)

add_executable(point2 ${SOURCE_FILES} main.cpp)

target_link_libraries(point2 libpoint2)

