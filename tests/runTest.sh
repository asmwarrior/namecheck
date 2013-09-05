#!/bin/bash

expectedExtension=".expected"
retrievedExtension=".retrieved"
patheExpectedFolder="../expectedResult/"
directory="testFiles/"

cd $directory
for file in $(ls *.cpp) ; 
do 
	g++ -fplugin=../../../../install/libs/libnamecheck.so -c $file &> $file""$retrievedExtension   	
	if diff $file""$retrievedExtension $patheExpectedFolder""$file""$expectedExtension; then
	 	echo -e $file "\e[1;32m"Test case OK"	\e[0m"
	else
	 	echo -e $file "\e[0;31mTest case failed\e[0m" 	
	fi
	rm $file""$retrievedExtension
done 

rm *.o