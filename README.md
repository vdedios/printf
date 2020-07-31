# Recode of original printf function

Recode of the print formatted string function found in stdio.h

# Test your ft_printf vs real printf

## Warning!
These tests do not cover all cases. The intention behind this is script is to provide a simple tool to make your own tests to prove against original printf function without having to code extra mains.

## USAGE
The script that runs everything (**run_tests.sh**) is found in the repo parent folder. It just automates comparison between original printf and your printf, and output the diff (if there is any differences)
in a external .txt file. This script has three usages.

*For mandatory testing:*
```
./run_tests.sh
```
*For leaks testing:*
```
./run_tests.sh leaks
```

*For bonus testing:*
```
./run_tests.sh bonus
```

In order to make it work just replace in run_tests.sh these variables with your own personal compiling and directories and preferences:

```
CC="gcc src/*.c libft/libft.a" 
LIB="-I header/"
```

## ADITIONAL COMMENTS
* You would need to have a makefile in order to use this test.
* All warning to error compiler flags are disabled due to some "undefined behaviour" tests done.
* All test source files are in /tests directory. Add all desired tests in the corresponding file
