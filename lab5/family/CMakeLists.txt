
project(family)

add_subdirectory(child)
add_subdirectory(parent)

add_executable(rodzinka main.cpp )

target_link_libraries(rodzinka libparent)
