# Test your ft_printf vs real printf

> These are simple tests to study %f, %e and %g behaviour.
It includes # flag to be tested also but you can modify it to test it with whatever flag you desire.

## USAGE
The script that runs everything (run_tests.sh) is found in the repo parent folder. It just automates compiling between to files, original printf and your printf, and output the diff (if there is)
in a external .txt file.

**main_o.c** is the original printf source and **main_f.c** is your ft_printf source. Just modify this files to test different cases.

**main_g.c** is just a simple main with some *%#g* cases I had problems with. You would have to compiled by yourself since is not compiled by the script. 

In order to make it work just replace, in run_tests.sh, these variables with your own personal compiling and directories preference.

```
CC="gcc -Wall -Werror -Wextra -g src/*.c libft/libft.a" 
LIB="-I header/"
```

You would need to have a makefile in order to use this test.
