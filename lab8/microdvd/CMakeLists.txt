
project(moviesubtitles)

set(HEDEAR_FILES MovieSubtitles.h SubtitleError.h)
set(SOURCE_FILES MovieSubtitles.cpp SubtitleError.cpp)

add_library(libmoviesubtitles STATIC ${SOURCE_FILES})
target_include_directories(libmoviesubtitles PUBLIC .)

add_executable(moviesubtitles ${SOURCE_FILES} main.cpp)

target_link_libraries(moviesubtitles libmoviesubtitles)

