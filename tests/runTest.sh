#!/bin/bash

#c++ test
expectedExtension=".expected"
retrievedExtension=".retrieved"
pathExpectedFolderCPP="../../expectedResult/c++/"
directoryCPP="DefaultRulesTest/testFiles/c++/"

cd $directoryCPP
 echo "---------------- C++ code ----------------"
 for cppFile in $(ls *.cpp);
 do 	
	g++ -fplugin=../../../../../../install/libs/libnamecheck.so -c $cppFile -fplugin-arg-libnamecheck-path=../../conffile.csv &> $cppFile""$retrievedExtension	
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
enumClassDeclaration="EnumClassDeclarationTest.cpp"
for cpp11File in $(ls *.cpp);
do	
	
 	if [ $cpp11File = $enumClassDeclaration ]; then
		g++ -fplugin=../../../../../../install/libs/libnamecheck.so -c $cpp11File -fplugin-arg-libnamecheck-path=../../conffile.csv &> $cpp11File""$retrievedExtension --std=c++0x	
		if diff $cpp11File""$retrievedExtension $pathExpectedFolderCPlusPlus""$cpp11File""$expectedExtension; then
	 		echo -e $cpp11File "\e[1;32m"Test case OK"	\e[0m"
		else
	 		echo -e $cpp11File "\e[0;31mTest case failed\e[0m"
		fi
		rm $cpp11File""$retrievedExtension
		rm *.o
 	else
		#check gcc version for test	
		gcc -dumpversion &> gccVersion
		echo "4.7" &> versionExpected
		if diff "./"gccVersion "./"versionExpected; then
			
			g++ -fplugin=../../../../../../install/libs/libnamecheck.so -c $cpp11File -fplugin-arg-libnamecheck-path=../../conffile.csv &> $cpp11File""$retrievedExtension --std=c++0x	
			if diff $cpp11File""$retrievedExtension $pathExpectedFolderCPlusPlus""$cpp11File""$expectedExtension; then
	 			echo -e $cpp11File "\e[1;32m"Test case OK"	\e[0m"
			else
	 			echo -e $cpp11File "\e[0;31mTest case failed\e[0m"
			fi
			rm $cpp11File""$retrievedExtension
			rm *.o
		else
			echo -e "\e[1;31m"$cpp11File" need gcc version 4.7\e[0m"
		fi		
		rm gccVersion
		rm versionExpected
	fi
done

#c test
pathExpectedFolder="../../expectedResult/c/"
directoryc="testFiles/c/"

cd ../..
cd $directoryc
echo "----------------- C code -----------------"
for cFile in $(ls *.c) ;
do
	g++ -fplugin=../../../../../../install/libs/libnamecheck.so -c $cFile -fplugin-arg-libnamecheck-path=../../conffile.csv &> $cFile""$retrievedExtension

	#check gcc version for test	
	gcc -dumpversion &> gccVersion
	echo "4.7" &> versionExpected
	if diff "./"gccVersion "./"versionExpected; then
		if diff $cFile""$retrievedExtension $pathExpectedFolder""$cFile""$expectedExtension"Gcc4.7"; then
	 		echo -e $cFile "\e[1;32m"Test case OK"	\e[0m"
		else
			echo -e $cFile "\e[0;31mTest case failed\e[0m"
		fi
	else
		if diff $cFile""$retrievedExtension $pathExpectedFolder""$cFile""$expectedExtension"Gcc4.6"; then
	 		echo -e $cFile "\e[1;32m"Test case OK"	\e[0m"
		else
			echo -e $cFile "\e[0;31mTest case failed\e[0m"
		fi
	fi
	rm gccVersion
	rm versionExpected
	rm $cFile""$retrievedExtension
done
rm *.o

#c++ main test
pathExpectedFolderCPP="../../expectedResult/c++main/"
directoryCPP="testFiles/c++main/"

cd ../..
cd $directoryCPP
 echo "---------------- C++ main code ----------------"
 for cppFile in $(ls *.cpp);
 do 	
	g++ -fplugin=../../../../../../install/libs/libnamecheck.so -c $cppFile -fplugin-arg-libnamecheck-path=../../conffile.csv &> $cppFile""$retrievedExtension	
	if diff $cppFile""$retrievedExtension $pathExpectedFolderCPP""$cppFile""$expectedExtension; then
	 	echo -e $cppFile "\e[1;32m"Test case OK"	\e[0m"
	else
		echo -e $cppFile "\e[0;31mTest case failed\e[0m"
	fi
	rm $cppFile""$retrievedExtension
done
rm *.o