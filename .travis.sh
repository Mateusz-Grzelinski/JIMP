#!/bin/bash

#CMAKEFlAGS="-DCMAKE_BUILD_TYPE=Debug"
#
##opcja k powoduje że make nie zamyka się po napotkaniu błędu
#MAKEFLAGS="--silent -k"
#
#
#cmake . $CMAKEFLAGS
#
#make  $MAKEFLAGS
#
#cd tests
#
##wejdż we wszystkie foldery zaczynające się od lab (np. lab1test):
#for testfolder in lab*; do
#	cd $testfolder
#
#	#jeśli istnieje, odpal lab?_all_tests
#	if [ -f *_all_tests ]; then
#		./*_all_tests
#		echo *all_tests
#	else
#	#jeśli nie ma, odpalaj testy pojedyńczo:
#		for singletest in lab*; do
#			#ten test buduje się, ale się loopuje. Co z tym fantem zrobić?
#			if [ ! "$singletest" = "lab4_simple_template_engine_injection_tests" ]; then
#			./$singletest
#			echo $singletest
#			fi;
#		done;
#	fi;
#
#	cd ..
#done;


set -evx
env | sort

mkdir build || true
mkdir build/$GTEST_TARGET || true
cd build/$GTEST_TARGET
cmake -Dgtest_build_samples=ON \
      -Dgtest_build_tests=ON \
      -DCMAKE_CXX_FLAGS=$CXX_FLAGS \
      ../../$GTEST_TARGET
make
CTEST_OUTPUT_ON_FAILURE=1 make test
