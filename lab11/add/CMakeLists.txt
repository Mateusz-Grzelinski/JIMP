
project(addtemplate)

set(HEDEAR_FILES AddTemplate.h)
set(SOURCE_FILES AddTemplate.cpp)

add_library(libaddtemplate STATIC ${SOURCE_FILES})
target_include_directories(libaddtemplate PUBLIC .)

add_executable(addtemplate ${SOURCE_FILES} main.cpp)

target_link_libraries(addtemplate libaddtemplate)

