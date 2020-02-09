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
			ft_printf("F:%.10f i:%d, j:%d, PREC:%.*f\n",a , i, j, i, a);
			ft_printf("F-#:%.10f i:%d, j:%d, PREC:%#.*f\n",a , i, j, i, a);

			ft_printf("E:%.10f i:%d, j:%d, PREC:%.*e\n",a , i, j, i, a);
			ft_printf("E-#:%.10f i:%d, j:%d, PREC:%#.*e\n",a , i, j, i, a);

			ft_printf("G:%.10f i:%d, j:%d, PREC:%.*g\n",a , i, j, i, a);
			ft_printf("G-#:%.10f i:%d, j:%d, PREC:%#.*g\n",a , i, j, i, a);
			i++;
		}
		i = 0;
		j++;
	}
}
