
project(dtab)

set(HEDEAR_FILES DTab.h)
set(SOURCE_FILES DTab.cpp)

add_library(libdtab STATIC ${SOURCE_FILES})
target_include_directories(libdtab PUBLIC .)

add_executable(dtab ${SOURCE_FILES} main.cpp)

target_link_libraries(dtab libdtab)

