#!/bin/bash

CC="gcc src/*.c libft/libft.a" 
LIB="-I header/"
rm -rf RESULTS.txt

make

if [ ! -f /output ]; then
	echo -e ...creating output folder...'\n'
	mkdir output
fi
if [ "$1" == "leaks" ]; then
	echo -e ...compiling your source and testing leaks...'\n'
	$CC -g tests/test_leaks.c $LIB -o output/printf_f
	./output/printf_f
else
	if [ "$1" == "bonus" ]; then
		SOURCE="test_bonus"
	else
		SOURCE="test_mandatory"
	fi
	if [ ! -f ./tests/original_printf.c ]; then
		echo -e ...creating test files...'\n'
		sed 's/ft_printf/printf/g' ./tests/$SOURCE.c > ./tests/original_printf.c
	else
		echo -e ...rebuilding test files...'\n'
		rm ./tests/original_printf.c
		sed 's/ft_printf/printf/g' ./tests/$SOURCE.c > ./tests/original_printf.c
	fi
	echo -e ...compiling original source...'\n'
	$CC -Wno-format tests/original_printf.c $LIB -o output/printf_o
	echo -e ...compiling your source...'\n'
	$CC tests/$SOURCE.c $LIB -o output/printf_f
	echo -e ...getting results...'\n'
	./output/printf_o | cat -e > src.txt
	./output/printf_f | cat -e > dst.txt
	if [$(diff src.txt dst.txt) == ""]; then
		echo -e ---Everything alright!✅ '\n'
	else
		echo -e .......Wrong output ❌
		diff src.txt dst.txt > RESULTS.txt
		echo -e Opening results...
		open RESULTS.txt
	fi
fi
echo -e cleaning everything...🗑
rm -rf output
rm -rf src.txt dst.txt ./tests/original_printf.c
