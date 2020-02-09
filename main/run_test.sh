 #!/bin/bash

rm -rf RESULTS.txt
make re
if [ ! -f /output ]; then
	echo creating output folder...
	mkdir output
fi
echo Compiling original source...
gcc -Wall -Werror -Wextra -g main/main_o.c src/*.c libft/libft.a -I header/ -o output/printf_o
./output/printf_o >> src.txt
echo Compiling replica source...
gcc -Wall -Werror -Wextra -g main/main_f.c src/*.c libft/libft.a -I header/ -o output/printf_f
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
