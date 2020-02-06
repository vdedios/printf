#include "printf.h"
#include <limits.h>

int main()
{
	float	a = 3423423423.141516;
	int 	i = 14;
	int 	j = 0;

	/*
	printf("o:i:%d, j:%d, PREC:%#.*f\n",i, j,  i, a);
	ft_printf("f:i:%d, j:%d, PREC:%#.*f\n",i, j,  i, a);
	*/
	while (j < 1000)
	{
		a = a - 0.01;
		while (i < 15)
		{
			ft_printf("NUM:%10f i:%d, j:%d, PREC:%.*e\n",a , i, j, i, a);
			i++;
		}
		i = 0;
		j++;
	}
}
