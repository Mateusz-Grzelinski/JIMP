
project(factorialtest)

set(HEDEAR_FILES FactorialTest.h)
set(SOURCE_FILES FactorialTest.cpp )


add_library(libfactorialltest STATIC ${SOURCE_FILES})
target_include_directories(libfactorialltest PUBLIC .)

add_executable(factoriallnormaltest ${SOURCE_FILES} main.cpp)
add_executable(factoriallgoogletest FactorialGoogleTest.cpp )

target_link_libraries(factoriallnormaltest libfactoriall)

target_link_libraries(factoriallgoogletest libfactoriall gtest gtest_main gmock gmock_main)


