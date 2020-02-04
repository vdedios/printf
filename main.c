#include "header/printf.h"

int main()
{
	int l;

	printf("%n\n", &l);
	ft_printf("%n\n", &l);
	system("leaks printf");
}
