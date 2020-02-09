#!/bin/bash

CC="gcc -Wall -Werror -Wextra -g src/*.c libft/libft.a" 
LIB="-I header/"
rm -rf RESULTS.txt
make re
if [ ! -f /output ]; then
	echo creating output folder...
	mkdir output
fi
echo Compiling original source...
$CC tests/main_o.c $LIB -o output/printf_o
./output/printf_o >> src.txt
echo Compiling your source...
$CC tests/main_f.c $LIB -o output/printf_f
./output/printf_f >> dst.txt
if [$(diff src.txt dst.txt) == ""]; then
	echo Everything alright!✅
else
	echo Wrong output ❌
	diff src.txt dst.txt >> RESULTS.txt
	echo Opening results...
	open RESULTS.txt
fi
echo cleaning everything...🗑
rm -rf output
rm -rf src.txt dst.txt
