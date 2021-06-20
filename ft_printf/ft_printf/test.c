#include "ft_printf.h"
#ifndef _STDIO_H_
#include <stdio.h>
#endif

int main()
{
	printf("[%5.7d]\n", 1);
	ft_printf("[%5.7d]\n", 1);
	return (0);
}