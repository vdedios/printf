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
	/*
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
	*/

	/*
	 ** Some more exhaustive tests for #g 
	 */
	/*
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
	*/

	/*
	 ** Tests for l, ll , h, and hh. Compile it only with gcc to avoid warning errors 
	 */
	/*
	ft_printf("Test long int:%ld\n", 0);
	ft_printf("Test long int:%ld\n", LONG_MAX);
	ft_printf("Test long int:%ld\n", LONG_MIN);
	ft_printf("Test long long int:%lld\n", 0);
	ft_printf("Test long long int:%lld\n", LLONG_MIN);
	ft_printf("Test long long int:%lld\n", LLONG_MAX);

	ft_printf("Test long x:%#lx\n", 0);
	ft_printf("Test long x:%#lx\n", LONG_MAX);
	ft_printf("Test long x:%#lx\n", LONG_MIN);
	ft_printf("Test long long x:%#llx\n", 0);
	ft_printf("Test long long x:%#llx\n", LLONG_MIN);
	ft_printf("Test long long x:%#llx\n", LLONG_MAX);

	ft_printf("Test unisgned long:%lu\n", 0);
	ft_printf("Test unisgned long:%lu\n", ULONG_MAX);
	ft_printf("Test unisgned long:%llu\n", 0);
	ft_printf("Test unisgned long:%llu\n", ULLONG_MAX);
	*/

	ft_printf("Test int short:%hd\n", 0);
	ft_printf("Test int short:%hd\n", (short)USHRT_MAX);
	ft_printf("Test int short:%hd\n", (short)SHRT_MIN);
	ft_printf("Test int short:%hd\n", (short)SHRT_MAX);
	ft_printf("Test int short:%hd\n", (short)UCHAR_MAX);
	ft_printf("Test int short:%hd\n", (short)CHAR_MAX);
	ft_printf("Test int short:%hd\n", (short)CHAR_MIN);
	ft_printf("Test int short:%hd\n", (short)UINT_MAX);
	ft_printf("Test int short:%hd\n", (short)INT_MAX);
	ft_printf("Test int short:%hd\n", (short)INT_MIN);
	ft_printf("Test int short:%hd\n", (short)ULONG_MAX);
	ft_printf("Test int short:%hd\n", (short)LONG_MAX);
	ft_printf("Test int short:%hd\n", (short)LONG_MIN);
	ft_printf("Test int short:%hd\n", (short)ULLONG_MAX);
	ft_printf("Test int short:%hd\n", (short)LLONG_MAX);
	ft_printf("Test int short:%hd\n", (short)LLONG_MIN);

	ft_printf("Test unsigned short:%hu\n", 0);
	ft_printf("Test unsigned short:%hu\n", (short)USHRT_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)SHRT_MIN);
	ft_printf("Test unsigned short:%hu\n", (short)SHRT_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)UCHAR_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)CHAR_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)CHAR_MIN);
	ft_printf("Test unsigned short:%hu\n", (short)UINT_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)INT_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)INT_MIN);
	ft_printf("Test unsigned short:%hu\n", (short)ULONG_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)LONG_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)LONG_MIN);
	ft_printf("Test unsigned short:%hu\n", (short)ULLONG_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)LLONG_MAX);
	ft_printf("Test unsigned short:%hu\n", (short)LLONG_MIN);



	ft_printf("Test x short:%hx\n", 0);
	ft_printf("Test x short:%hx\n", (short)USHRT_MAX);
	ft_printf("Test x short:%hx\n", (short)SHRT_MIN);
	ft_printf("Test x short:%hx\n", (short)SHRT_MAX);
	ft_printf("Test x short:%hx\n", (short)UCHAR_MAX);
	ft_printf("Test x short:%hx\n", (short)CHAR_MAX);
	ft_printf("Test x short:%hx\n", (short)CHAR_MIN);
	ft_printf("Test x short:%hx\n", (short)UINT_MAX);
	ft_printf("Test x short:%hx\n", (short)INT_MAX);
	ft_printf("Test x short:%hx\n", (short)INT_MIN);
	ft_printf("Test x short:%hx\n", (short)ULONG_MAX);
	ft_printf("Test x short:%hx\n", (short)LONG_MAX);
	ft_printf("Test x short:%hx\n", (short)LONG_MIN);
	ft_printf("Test x short:%hx\n", (short)ULLONG_MAX);
	ft_printf("Test x short:%hx\n", (short)LLONG_MAX);
	ft_printf("Test x short:%hx\n", (short)LLONG_MIN);

	/*
	ft_printf("Test x char:%#hhx\n", 0);
	ft_printf("Test x char:%#hhx\n", SCHAR_MIN);
	ft_printf("Test x char:%#hhx\n", SCHAR_MAX);
	ft_printf("Test x char:%#hhx\n", UCHAR_MAX);
	ft_printf("Test x char:%#hhx\n", CHAR_MIN);
	*/

	/*
	 ** Tests for # with xX
	 */
	/*
	i = -15;
	j = 0;
	int k = 0;
	int f = 123456;
	while (i < 15)
	{
		while (k < 200)
		{
			while (j < 10)
			{
				//ft_printf("OUT:%.15f\n", f);
				ft_printf("Test #g: width%d precision%d NUM:%d |#|:%#*.*x\n", i, j, k, i, j, f);
				ft_printf("Test #g: width%d precision%d NUM:%d |#-|:%#-*.*x\n", i, j, k, i, j, f);
				ft_printf("Test #g: width%d precision%d NUM:%d |#0|:%#0*.*x\n", i, j, k, i, j, f);
				j++;
			}
			j = 0;
			k++;
			f -= 3;
		}
		k = 0;	
		i++;
	}
	*/
}
