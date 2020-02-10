#include "printf.h"
#include <limits.h>

int main()
{
	float	a = 3.1415;
	int 	i = 0;
	int 	j = 0;

	/*
	** Tests for f, e, g with and without # flag. Compile it only with gcc to avoid warning errors 
	*/
	while (j < 1000)
	{
		a = a - 0.01;
		while (i < 10)
		{
			ft_printf("Test f:%.10f i:%d, j:%d, PREC:%.*f\n",a , i, j, i, a);
			ft_printf("Test #f:%.10f i:%d, j:%d, PREC:%#.*f\n",a , i, j, i, a);

			ft_printf("Test e:%.10f i:%d, j:%d, PREC:%.*e\n",a , i, j, i, a);
			ft_printf("Test #e:%.10f i:%d, j:%d, PREC:%#.*e\n",a , i, j, i, a);

			ft_printf("Test g:%.10f i:%d, j:%d, PREC:%.*g\n",a , i, j, i, a);
			ft_printf("Test #g:%.10f i:%d, j:%d, PREC:%#.*g\n",a , i, j, i, a);
			i++;
		}
		i = 0;
		j++;
	}

	i = 0;
	j = 0;
	a = 31415;
	while (j < 1000)
	{
		a = a - 0.01;
		while (i < 6)
		{
			ft_printf("Test f- i:%d, j:%d, PREC:%.*f\n",a , i, j, i, a);
			ft_printf("Test #f- i:%d, j:%d, PREC:%#.*f\n",a , i, j, i, a);

			ft_printf("Test e- i:%d, j:%d, PREC:%.*e\n",a , i, j, i, a);
			ft_printf("Test #e- i:%d, j:%d, PREC:%#.*e\n",a , i, j, i, a);

			ft_printf("Test g- i:%d, j:%d, PREC:%.*g\n",a , i, j, i, a);
			ft_printf("Test #g- i:%d, j:%d, PREC:%#.*g\n",a , i, j, i, a);
			i++;
		}
		i = 0;
		j++;
	}

	/*
	** Some more exhaustive tests for #g 
	*/
	ft_printf("Exhaustive g tests: %.6f	3.	%#.*g	\n", 3.1415, 0, 3.1415);
	ft_printf("Exhaustive g tests: %.6f	6.	%#.*g	\n", -0.9884966612, 6, -0.9884966612);
	ft_printf("Exhaustive g tests: %.6f	2.	%#.*g	\n", 0.9915020466, 2, 0.9915020466);
	ft_printf("Exhaustive g tests: %.6f	1.	%#.*g	\n", 9.984020466 , 1, 9.984020466);
	ft_printf("Exhaustive g tests: %.6f	1.	%#.*g	\n", 0.984966516 , 1, 0.984966516);
	ft_printf("Exhaustive g tests: %.6f	1.	%#.*g	\n", 0.0984966516 , 1, 0.0984966516);
	ft_printf("Exhaustive g tests: %.6f	1.	%#.*g	\n", 0.0000984966516, 1, 0.0000984966516);
	ft_printf("Exhaustive g tests: %.6f	3.	%#.*g	\n", 99.984966516, 3, 99.984966516);
	ft_printf("Exhaustive g tests: %.6f	4.	%#.*g	\n", 999.984966516 , 4, 999.984966516);
	ft_printf("Exhaustive g tests: %.6f	1.	%#.*g	\n", 9.944020466 , 1, 9.944020466);


	/*
	** Tests for l, ll , h, and hh. Compile it only with gcc to avoid warning errors 
	*/
	ft_printf("Test long int:%ld\n", LONG_MAX);
	ft_printf("Test long int:%ld\n", LONG_MIN);
	ft_printf("Test long long int:%lld\n", LLONG_MIN);
	ft_printf("Test long long int:%lld\n", LLONG_MAX);

	ft_printf("Test long x:%#lx\n", LONG_MAX);
	ft_printf("Test long x:%#lx\n", LONG_MIN);
	ft_printf("Test long long x:%#llx\n", LLONG_MIN);
	ft_printf("Test long long x:%#llx\n", LLONG_MAX);

	ft_printf("Test unisgned long:%lu\n", ULONG_MAX);
	ft_printf("Test unisgned long:%llu\n", ULLONG_MAX);

	ft_printf("Test int short:%hd\n", SHRT_MIN);
	ft_printf("Test int short:%hd\n", SHRT_MAX);
	ft_printf("Test unsigned short:%hu\n", USHRT_MAX);

	ft_printf("Test x short:%hx\n", SHRT_MIN);
	ft_printf("Test x short:%hx\n", SHRT_MAX);
	ft_printf("Test x short:%hx\n", USHRT_MAX);

	ft_printf("Test x char:%#hhx\n", SCHAR_MIN);
	ft_printf("Test x char:%#hhx\n", SCHAR_MAX);
	ft_printf("Test x char:%#hhx\n", UCHAR_MAX);
	ft_printf("Test x char:%#hhx\n", CHAR_MIN);

	/*
	** Tests for # with xX
	*/
	i = 0;
	j = 0;
	while (i < 20)
	{
		while (j < 20)
		{
			ft_printf("Test #x: %#*.*hx\n", i, j, CHAR_MAX);
			ft_printf("Test #X: %#*.*hx\n", i, j, CHAR_MAX);
			j++;
		}
	j = 0;
	i++;
	}
}
