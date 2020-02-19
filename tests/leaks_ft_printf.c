#include "printf.h"
#include <limits.h>
#include <float.h>

int main()
{
	//ft_printf("esto es %c %d %i %f %g %e %g \n una prueba de leaks\n\n", 0, 0, 0, 0, 0, 0, 0);
	//system("leaks printf");
	ft_printf("f:%.1f\n", 3.85);
	printf("o:%.1f\n", 3.85);

	ft_printf("f:%#010.0e\n", 0.0);
	printf("o:%#010.0e\n", 0.0);
}
