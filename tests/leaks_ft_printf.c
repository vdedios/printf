#include "printf.h"
#include <limits.h>
#include <float.h>

int main()
{
	//ft_printf("esto es %c %d %i %f %g %e %g \n una prueba de leaks\n\n", 0, 0, 0, 0, 0, 0, 0);
	//system("leaks printf");
	ft_printf("f:%010.10x\n", 25);
	printf("o:%010.10x\n", 25);
}
