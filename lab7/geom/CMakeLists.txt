
project(kolo)

set(HEDEAR_FILES Kolo.h Kula.h)
set(SOURCE_FILES Kolo.cpp Kula.cpp)

add_library(libkolo STATIC ${SOURCE_FILES})
target_include_directories(libkolo PUBLIC .)

add_executable(ksztalty_geometryczne ${SOURCE_FILES} main.cpp Shape.cpp Shape.h Triangle.cpp Triangle.h Square.cpp Square.h)

target_link_libraries(ksztalty_geometryczne libkolo)
