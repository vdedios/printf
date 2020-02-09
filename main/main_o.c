#include "printf.h"
#include <limits.h>

int main()
{
	float	a = 3.1415;
	int 	i = 0;
	int 	j = 0;

	while (j < 1000)
	{
		a = a - 0.01;
		while (i < 10)
		{
			printf("NUM:%.10f i:%d, j:%d, PREC:%.*g\n",a , i, j, i, a);
			i++;
		}
		i = 0;
		j++;
	}
}
