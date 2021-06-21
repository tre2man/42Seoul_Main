#include "ft_printf.h"
#ifndef _STDIO_H_
#include <stdio.h>
#endif

int main()
{
	const char *input = "[ 0*%-0*.10d*0 0*%-0*.0d*0 ]";
	int a;
	a = printf(input, 21, 1021, 21, -1011);
	printf("\n%d\n", a);
	a = ft_printf(input, 21, 1021, 21, -1011);
	printf("\n%d\n", a);
	return (0);
}