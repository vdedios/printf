#include "printf.h"
#include <limits.h>

/*
** A general main
*/

int main()
{	
	ft_printf("%c %c %c", 0, 'a', 0);
	system("leaks printf");
}
