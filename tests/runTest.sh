#!/bin/bash

#c++ test
expectedExtension=".expected"
retrievedExtension=".retrieved"
patheExpectedFolder="../../expectedResult/c++/"
directoryCPlusPlus="testFiles/c++/"

cd $directoryCPlusPlus
echo "---------------- C++ code ----------------"
for cppFile in $(ls *.cpp) ;
do
	g++ -fplugin=../../../../../install/libs/libnamecheck.so -c $cppFile &> $cppFile""$retrievedExtension
	if diff $cppFile""$retrievedExtension $patheExpectedFolder""$cppFile""$expectedExtension; then
	 	echo -e $cppFile "\e[1;32m"Test case OK"	\e[0m"
	else
		echo -e $cppFile "\e[0;31mTest case failed\e[0m"
	fi
	rm $cppFile""$retrievedExtension
done
rm *.o

#c test
patheExpectedFolder="../../expectedResult/c/"
directoryc="testFiles/c/"

cd ../..
cd $directoryc
echo "----------------- C code -----------------"
for cFile in $(ls *.c) ;
do
	g++ -fplugin=../../../../../install/libs/libnamecheck.so -c $cFile &> $cFile""$retrievedExtension
	if diff $cFile""$retrievedExtension $patheExpectedFolder""$cFile""$expectedExtension; then
	 	echo -e $cFile "\e[1;32m"Test case OK"	\e[0m"
	else
		echo -e $cFile "\e[0;31mTest case failed\e[0m"
	fi
	rm $cFile""$retrievedExtension
done
rm *.o
