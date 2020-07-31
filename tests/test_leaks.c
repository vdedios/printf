#include <stdio.h>
#include <limits.h>
#include "printf.h"

/*
** A simple list of most typical ft_printf failures
** with LEAKS
*/

int main()
{
	int n;

	ft_printf("-------------HELLO WORLD----------------");
	n = ft_printf("%c", 0);
	n += ft_printf("%s", "Ho\n	ka");
	n += ft_printf("%d", INT_MAX);
	n += ft_printf("%i", INT_MIN);
	n += ft_printf("%x",UINT_MAX);
	n += ft_printf("%p",&n);
	n += ft_printf("%3p", NULL);
	n += ft_printf("%%");
	n += ft_printf("%.0x",0);
	n += ft_printf("%.0d",0);
	n += ft_printf("%10.0x",0);
	n += ft_printf("%10.0d",0);
	n += ft_printf("%s %d %i %x %p %3p %% %.0x %.0d %10.0d %10.0x", "Ho\n	ka", INT_MAX, INT_MIN, UINT_MAX, &n, NULL, 0, 0, 0, 0);
	n += ft_printf("%c", 0);
	n += ft_printf("%.3s", "Ho\n	ka");
	n += ft_printf("%.d", INT_MAX);
	n += ft_printf("%10.1000i", INT_MIN);
	n += ft_printf("%0.10x",UINT_MAX);
	n += ft_printf("%50p",&n);
	n += ft_printf("%3p", NULL);
	n += ft_printf("%%100");
	n += ft_printf("%.20x",0);
	n += ft_printf("%.20d",0);
	n += ft_printf("%10.50x",0);
	n += ft_printf("%10.50d",0);
	n += ft_printf("%.3s %.d %10.1000i %0.10x %50p %3p %%100 %.20x %.20d %10.50d %10.50x", "Ho\n	ka", INT_MAX, INT_MIN, UINT_MAX, &n, NULL, 0, 0, 0, 0);
	ft_printf("\n\nOUTPUT: %d\n", n);
	system("leaks printf");
    return (0);
}
