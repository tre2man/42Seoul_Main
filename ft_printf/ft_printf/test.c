#include "ft_printf.h"
#ifndef _STDIO_H_
#include <stdio.h>
#endif

int main()
{
	const char *input = "[%05.4d]";
	int a;
	a = printf(input, 3);
	printf("\n%d\n", a);
	a = ft_printf(input, 3);
	printf("\n%d\n", a);
	return (0);
}