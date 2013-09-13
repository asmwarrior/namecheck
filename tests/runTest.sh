#!/bin/bash

#c++ test
expectedExtension=".expected"
retrievedExtension=".retrieved"
pathExpectedFolderCPP="../../expectedResult/c++/"
directoryCPP="testFiles/c++/"

cd $directoryCPP
 echo "---------------- C++ code ----------------"
 for cppFile in $(ls *.cpp);
 do 	
	g++ -fplugin=../../../../../install/libs/libnamecheck.so -c $cppFile &> $cppFile""$retrievedExtension	
	if diff $cppFile""$retrievedExtension $pathExpectedFolderCPP""$cppFile""$expectedExtension; then
	 	echo -e $cppFile "\e[1;32m"Test case OK"	\e[0m"
	else
		echo -e $cppFile "\e[0;31mTest case failed\e[0m"
	fi
	rm $cppFile""$retrievedExtension
done
rm *.o

#c++ test
pathExpectedFolderCPlusPlus="../../expectedResult/c++11/"
directoryCPlusPlus="testFiles/c++11/"
cd ../..
cd $directoryCPlusPlus

echo "---------------- C++11 code ----------------"
for cpp11File in $(ls *.cpp);
do	
	g++ -fplugin=../../../../../install/libs/libnamecheck.so -c $cpp11File &> $cpp11File""$retrievedExtension --std=c++0x	
	if diff $cpp11File""$retrievedExtension $pathExpectedFolderCPlusPlus""$cpp11File""$expectedExtension; then
	 	echo -e $cpp11File "\e[1;32m"Test case OK"	\e[0m"
	else
	 	echo -e $cpp11File "\e[0;31mTest case failed\e[0m"
	fi
	rm $cpp11File""$retrievedExtension
done
rm *.o

#c test
pathExpectedFolder="../../expectedResult/c/"
directoryc="testFiles/c/"

cd ../..
cd $directoryc
echo "----------------- C code -----------------"
for cFile in $(ls *.c) ;
do
	g++ -fplugin=../../../../../install/libs/libnamecheck.so -c $cFile &> $cFile""$retrievedExtension
	if diff $cFile""$retrievedExtension $pathExpectedFolder""$cFile""$expectedExtension; then
	 	echo -e $cFile "\e[1;32m"Test case OK"	\e[0m"
	else
		echo -e $cFile "\e[0;31mTest case failed\e[0m"
	fi
	rm $cFile""$retrievedExtension
done
rm *.o