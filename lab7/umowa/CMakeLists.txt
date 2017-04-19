
project(umowa)

set(HEDEAR_FILES Umowa.h)
set(SOURCE_FILES Umowa.cpp)

add_library(libumowa STATIC ${SOURCE_FILES})
target_include_directories(libumowa PUBLIC .)

add_executable(umowa ${SOURCE_FILES} main.cpp)

target_link_libraries(umowa libumowa)
