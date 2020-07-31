#include <stdio.h>
#include <limits.h>

/*
** A simple list of most typical printf failures
*/

int main()
{
	int n;

	printf("-------------HELLO WORLD----------------");
	n = printf("%c", 0);
	n += printf("%s", "Ho\n	ka");
	n += printf("%d", INT_MAX);
	n += printf("%i", INT_MIN);
	n += printf("%x",UINT_MAX);
	n += printf("%p",&n);
	n += printf("%3p", NULL);
	n += printf("%%");
	n += printf("%.0x",0);
	n += printf("%.0d",0);
	n += printf("%10.0x",0);
	n += printf("%10.0d",0);
	n += printf("%s %d %i %x %p %3p %% %.0x %.0d %10.0d %10.0x", "Ho\n	ka", INT_MAX, INT_MIN, UINT_MAX, &n, NULL, 0, 0, 0, 0);
	n += printf("%c", 0);
	n += printf("%.3s", "Ho\n	ka");
	n += printf("%.d", INT_MAX);
	n += printf("%10.1000i", INT_MIN);
	n += printf("%0.10x",UINT_MAX);
	n += printf("%50p",&n);
	n += printf("%3p", NULL);
	n += printf("%%100");
	n += printf("%.20x",0);
	n += printf("%.20d",0);
	n += printf("%10.50x",0);
	n += printf("%10.50d",0);
	n += printf("%.3s %.d %10.1000i %0.10x %50p %3p %%100 %.20x %.20d %10.50d %10.50x", "Ho\n	ka", INT_MAX, INT_MIN, UINT_MAX, &n, NULL, 0, 0, 0, 0);
	printf("\n\nOUTPUT: %d\n", n);
    return (0);
}
