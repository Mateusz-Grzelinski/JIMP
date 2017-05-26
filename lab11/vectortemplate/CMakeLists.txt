
project(vectortemplate)

set(HEDEAR_FILES VectorTemplate.h)
set(SOURCE_FILES VectorTemplate.cpp)

add_library(libvectortemplate STATIC ${SOURCE_FILES})
target_include_directories(libvectortemplate PUBLIC .)

add_executable(vectortemplate ${SOURCE_FILES} )

target_link_libraries(vectortemplate libvectortemplate)

