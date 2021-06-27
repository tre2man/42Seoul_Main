#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	const char *str = "[%.0x]";
	a = printf(str, 0);
	printf("\n%d\n", a - 2);
	a = ft_printf(str, 0);
	printf("\n%d\n", a - 2);
}