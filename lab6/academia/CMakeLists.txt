
project(student)

set(HEDEAR_FILES Student.h StudyYear.h StudentRepository.h)
set(SOURCE_FILES Student.cpp StudyYear.cpp StudentRepository.cpp)


add_library(libstudentrepository STATIC ${SOURCE_FILES})
target_include_directories(libstudentrepository PUBLIC .)

add_executable(student ${SOURCE_FILES} main.cpp)

target_link_libraries(student libstudentrepository)

