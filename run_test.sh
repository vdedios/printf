#!/bin/bash

CC="gcc src/*.c libft/libft.a" 
LIB="-I header/"
rm -rf RESULTS.txt
make re
if [ ! -f /output ]; then
	echo creating output folder...
	mkdir output
fi
if [ "$1" == "leaks" ]; then
	echo Compiling your source...
	$CC tests/leaks_ft_printf.c $LIB -o output/printf_f
	./output/printf_f
else
	if [ ! -f ./tests/original_printf.c ]; then
		echo creating test files...
		sed 's/ft_printf/printf/g' ./tests/tests_ft_printf.c > ./tests/original_printf.c
	else
		echo rebuilding test files...
		rm ./tests/original_printf.c
		sed 's/ft_printf/printf/g' ./tests/tests_ft_printf.c > ./tests/original_printf.c
	fi
	echo Compiling original source...
	$CC -Wno-format tests/original_printf.c $LIB -o output/printf_o
	echo Compiling your source...
	$CC tests/tests_ft_printf.c $LIB -o output/printf_f
	echo Getting results...
	./output/printf_o > src.txt
	./output/printf_f > dst.txt
	if [$(diff src.txt dst.txt) == ""]; then
		echo Everything alright!✅
	else
		echo Wrong output ❌
		diff src.txt dst.txt > RESULTS.txt
		echo Opening results...
		open RESULTS.txt
	fi
fi
echo cleaning everything...🗑
rm -rf output
rm -rf src.txt dst.txt ./tests/original_printf.c
