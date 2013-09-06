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
