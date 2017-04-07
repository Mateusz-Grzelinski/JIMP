
project(word)

set(HEDEAR_FILES Word.h Counts.h WordCounter.h)
set(SOURCE_FILES Word.cpp Counts.cpp WordCounter.cpp)

add_library(libwordcounter STATIC ${SOURCE_FILES})
target_include_directories(libwordcounter PUBLIC .)

add_executable(wordcounter ${SOURCE_FILES} main.cpp  )

target_link_libraries(wordcounter libwordcounter)

