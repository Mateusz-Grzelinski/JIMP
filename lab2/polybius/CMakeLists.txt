project(Polybius)

set(HEDEAR_FILES Polybius.h)
set(SOURCE_FILES Polybius.cpp)

add_library(libpolybius STATIC ${SOURCE_FILES})
target_include_directories(libpolybius PUBLIC .)

add_executable(Polybius ${SOURCE_FILES} main.cpp)

target_link_libraries(Polybius libpolybius)