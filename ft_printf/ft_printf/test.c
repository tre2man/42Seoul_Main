#include "ft_printf.h"
#ifndef _STDIO_H_
#include <stdio.h>
#endif

int main()
{
	const char *input = "%% %% %%";
	int a;
	a = printf("%%");
	printf("\n%d\n", a);
	a = ft_printf("%%");
	printf("\n%d\n", a);
	return (0);
}