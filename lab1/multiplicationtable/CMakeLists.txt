project(multiplicationtable)

set(HEDEAR_FILES MultiplicationTable.h)
set(SOURCE_FILES MultiplicationTable.cpp)

add_library(libmultiplicationtable STATIC ${SOURCE_FILES})
target_include_directories(libmultiplicationtable PUBLIC .)

add_executable(multiplication ${SOURCE_FILES} main.cpp )

target_link_libraries(multiplication libmultiplicationtable)

