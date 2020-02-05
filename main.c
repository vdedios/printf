#include "header/printf.h"
#include <limits.h>

int main()
{
	printf("o:%lx, %lx\n", 0ul, ULONG_MAX);
	ft_printf("f:%lx, %lx\n", 0ul, ULONG_MAX);
}
