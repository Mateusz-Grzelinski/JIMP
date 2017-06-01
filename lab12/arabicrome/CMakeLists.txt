
project(arabicroman)

set(HEDEAR_FILES ArabicToRoman.h RomanToArabic.h ArabicRomeConsversion.h)
set(SOURCE_FILES ArabicRomeConsversion.cpp)

add_library(libarabicroman STATIC ${SOURCE_FILES})
target_include_directories(libarabicroman PUBLIC .)

add_executable(arabicroman ${SOURCE_FILES} )

target_link_libraries(arabicroman libarabicroman)

