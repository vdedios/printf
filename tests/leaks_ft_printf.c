#include "printf.h"
#include <limits.h>

int main()
{
	//ft_printf("esto es %c %d %i %f %g %e %g \n una prueba de leaks\n", 0, 0, 0, 0, 0, 0, 0);
	//system("leaks printf");
	
	printf("o:%.4g\n",9990.3515625000);
	ft_printf("f:%.4g\n",9990.3515625000);
}
