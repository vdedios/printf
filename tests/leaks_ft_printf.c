#include "printf.h"
#include <limits.h>

int main()
{
	ft_printf("esto es %c %d %i %f %g %e %g \n una prueba de leaks\n\n", 0, 0, 0, 0, 0, 0, 0);
	system("leaks printf");
}
