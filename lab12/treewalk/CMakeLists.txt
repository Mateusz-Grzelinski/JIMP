
project(order)

set(HEDEAR_FILES Order.h)
set(SOURCE_FILES Order.cpp)

add_library(liborder STATIC ${SOURCE_FILES})
target_include_directories(liborder PUBLIC .)

add_executable(order ${SOURCE_FILES} main.cpp)

target_link_libraries(order liborder)

