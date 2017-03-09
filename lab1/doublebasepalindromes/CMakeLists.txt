project(DoubleBasePalindromes)

set(HEDEAR_FILES DoubleBasePalindromes.h ConvertToBase2.h)
set(SOURCE_FILES DoubleBasePalindromes.cpp ConvertToBase2.cpp )

add_library(libdoublebasepalindromes STATIC ${SOURCE_FILES} )
target_include_directories(libdoublebasepalindromes PUBLIC .)

add_executable(DoubleBasePalindromes ${SOURCE_FILES} main.cpp )

target_link_libraries(DoubleBasePalindromes libdoublebasepalindromes)
