
project(factorial)

set(HEDEAR_FILES Factorial.h)
set(SOURCE_FILES Factorial.cpp)

add_library(libfactoriall STATIC ${SOURCE_FILES})
target_include_directories(libfactoriall PUBLIC .)

add_executable(factoriall ${SOURCE_FILES} )

target_link_libraries(factoriall libfactoriall)

