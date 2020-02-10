# Test your ft_printf vs real printf

> These are simple tests to study behaviour with some extreme cases in l, ll, h, hh length modifiers, and # flag.
It also test leaks.

## USAGE
The script that runs everything (**run_tests.sh**) is found in the repo parent folder. It just automates comparison between original printf and your printf, and output the diff (if there is any differences)
in a external .txt file. This script has two usages.

*For normal testing:*
```
./run_tests.sh
```
*For leaks testing:*
```
./run_tests.sh leaks
```

In order to make it work just replace, in run_tests.sh, these variables with your own personal compiling and directories preference:
```
CC="gcc src/*.c libft/libft.a" 
LIB="-I header/"
```
## ADITIONAL COMMENTS
* You would need to have a makefile in order to use this test.
* All warning to error compiler flags are disabled due to some "undefined behaviour" tests done.
* **tests/tests_ft_printf.c** is the file that contains all the tests. You can modify this file in order to test all different cases you desire.
* **tests/leaks_ft_printf.c** is the file that contains a leaks simple test.
