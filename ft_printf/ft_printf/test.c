#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	const char *str = "[ 0*%0-*.*x*0 0*%0*.*x*0 ]";
	a = printf(str, 6, 2, 102, 10, 21, -101);
	printf("\n%d\n", a - 2);
	a = ft_printf(str, 6, 2, 102, 10, 21, -101);
	printf("\n%d\n", a - 2);
}